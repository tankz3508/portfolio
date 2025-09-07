# Shop System

A safe and fully functional console-based shop system implemented in C++.

Demonstrates OOP, inventory management, and simple error handling.

## How to Use

Example usage in `main.cpp`:

```cpp
Shop shop {};
Player player{"Player", 1000.0};

// Add items to the shop
shop.add_item("Double Sided Dagger", 199.99, ItemType::Dagger};
shop.add_item("Basic Dagger", 19.99, ItemType::Dagger);
shop.add_item("Sword", 500.0, ItemType::Sword);
shop.add_item("High Tech Machine Gun", 1999.99, ItemType::MachineGun);

// List player inventory
player.list_inventory();

// Buy items from shop
player.add_item(shop, "Double Sided Dagger");
player.add_item(shop, "Double Sided Sword");
player.add_item(shop, "High Tech Machine Gun");
player.list_inventory();

// Sell item from inventory
player.sell_item("Double Sided Dagger");
```

> **:warning: Note**
> This is a hobby project to practice classes, vectors, enums, and basic OOP in C++.
