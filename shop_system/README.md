# Shop System

A fully working, safe, and fast Shop system implemented in C++

It's safe, fast, and works great.

# How to use?

```cpp
    Shop shop{}; // Declare Shop class
    Player player{"Tankz", 1000.0}; // Declare Player with {(std::string)name, (double)balance}

    // Adding items to the shop with {(std::string)name, (double)price, (enum::ItemType)type)}
    shop.add_item("Double Sided Dagger", 199.99, ItemType::Dagger);
    shop.add_item("Basic Dagger", 19.99, ItemType::Dagger);
    shop.add_item("Sword", 500.0, ItemType::Sword);
    shop.add_item("High Tech Machine Gun", 1999.99, ItemType::MachineGun);

    std::cout << "\n\n------------------------------------\n\n";

    // Listing player inventory
    player.list_inventory();

    // Adding item to player
    // passing in shop is required to check the actual price, type, etc. in the above declared shop.
    // adding: {(class)Shop, (std::string)name)}
    player.add_item(shop, "Double Sided Dagger");
    player.add_item(shop, "Double Sided Sword");
    player.add_item(shop, "High Tech Machine Gun");
    player.list_inventory();

    // Selling item from inventory
    // Adds the item price back to the player's balance
    player.sell_item("Double Sided Dagger");

    return 0;
```

## :warning: This is a hobby project :warning:
