#include <iostream>
#include <vector>

enum class ItemType {
    Knife,
    Sword,
    Dagger,
    Bow,
    Pistol,
    MachineGun,
    Potion,
    max_item,
};


std::string to_string(ItemType item) {
    switch (item) {
        case ItemType::Knife: return "Knife";
        case ItemType::Sword: return "Sword";
        case ItemType::Dagger: return "Dagger";
        case ItemType::Bow: return "Bow";
        case ItemType::Pistol: return "Pistol";
        case ItemType::MachineGun: return "Machine Gun";
        case ItemType::Potion: return "Potion";
        default: return "???";
    }
}


struct Item {
    std::string item_name;
    double price;
    ItemType item_type;
};

class Shop {
private:
    std::string m_name;
    std::vector<Item> m_items;
public:
    Shop(const std::string& name="Item Shop") : m_name(name) {}

    void list_items() {
        for (const auto& item : m_items) {
            std::cout << item.item_name << " | Type: " << to_string(item.item_type) << " | Price: " << item.price << '\n';
        }
    }

    void add_item(const std::string& name, double price, ItemType item_type) {
        for (const auto& item : m_items) {
            if (item.item_name == name && item.item_type == item_type && item.price == price) {
                std::cout << "Warning: Item already exists in the shop!";
                return;
            }
        }
        m_items.emplace_back(name, price, item_type);
        std::cout << "Added item: " << name << " of Type: " << to_string(item_type) << " with price: " << price << '\n';
    }

    void remove_item(const std::string& name) {
        bool found = false;
        for (int i = 0; i < m_items.size(); i++) {
            if (m_items[i].item_name == name) {
                m_items.erase(m_items.begin() + i);
                found = true;
                break;
            }
        }

        if (found) {
            std::cout << "Removed item: " << name << '\n';
        } else {
            std::cout << "Item doesn't exist!\n";
        }

    }

    const std::vector<Item>& getItems() const {
        return m_items;
    }
};

class Player {
private:
    std::string m_name;
    double m_balance;
    std::vector<Item> m_inventory;
public:
    explicit Player(const std::string& name="Player", double balance=0) : m_name(name), m_balance(balance) {}

    void add_item(Shop& shop, const std::string& name) {
        bool found = false;
        for (const auto& item : shop.getItems()) {
            if (item.item_name == name) {
                found = true;
                if (m_balance >= item.price) {
                    m_balance -= item.price;
                    m_inventory.emplace_back(item);
                    std::cout << "Bought " << item.item_name << " for " << item.price << '\n';
                    std::cout << "Balance: " << m_balance << '\n';
                } else {
                    std::cout << "Not enough money!\n";
                }
                break;
            }
        }

        if (!found) {
            std::cout << "Item does not exist!\n";
        }
    }

    void sell_item(const std::string& name) {
        bool sold = false;
        for (int i = 0; i < m_inventory.size(); i++) {
            if (m_inventory[i].item_name == name) {
                m_balance += m_inventory[i].price;
                m_inventory.erase(m_inventory.begin() + i);
                sold = true;
                break;
            }
        }
        if (sold) {
            std::cout << "Sold item " << name << "!\nNew balance: " << m_balance << '\n';
        } else {
            std::cout << "Item " << name << " does not exist!\n";
        }

    }

    void list_inventory() {
        std::cout << "Current balance: " << m_balance << '\n';
        if (m_inventory.empty()) {
            std::cout << "Empty inventory!\n";
            return;
        }

        for (const auto& item : m_inventory) {
            std::cout << item.item_name << " | Type: " << to_string(item.item_type) << " | Price: " << item.price << '\n';
        }
    }
};

int main() {
    Shop shop{};
    Player player{"Tankz", 1000.0};

    shop.add_item("Double Sided Dagger", 199.99, ItemType::Dagger);
    shop.add_item("Basic Dagger", 19.99, ItemType::Dagger);
    shop.add_item("Sword", 500.0, ItemType::Sword);
    shop.add_item("High Tech Machine Gun", 1999.99, ItemType::MachineGun);

    std::cout << "\n\n------------------------------------\n\n";

    player.list_inventory();
    player.add_item(shop, "Double Sided Dagger");
    player.add_item(shop, "Double Sided Sword");
    player.add_item(shop, "High Tech Machine Gun");
    player.list_inventory();
    player.sell_item("Double Sided Dagger");

    return 0;
}
