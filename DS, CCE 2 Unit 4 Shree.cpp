#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For atoi
#include <cctype>  // For isdigit

using namespace std;

struct MenuNode
{
    string name;
    vector<MenuNode*> children;

    MenuNode(string menuName)
    {
        name = menuName;
    }
};

// Display the complete menu hierarchy
void displayMenu(MenuNode* root, int level = 0)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "    ";

    cout << "|-- " << root->name << endl;

    // Replaced range-based for loop with traditional index loop for C++98
    for (size_t i = 0; i < root->children.size(); i++)
    {
        displayMenu(root->children[i], level + 1);
    }
}

// Search for a menu item by name
MenuNode* searchMenu(MenuNode* root, string name)
{
    if (root == NULL)
        return NULL;

    if (root->name == name)
        return root;

    for (size_t i = 0; i < root->children.size(); i++)
    {
        MenuNode* result = searchMenu(root->children[i], name);

        if (result != NULL)
            return result;
    }

    return NULL;
}

// Add a submenu under an existing menu
void addSubmenu(MenuNode* root)
{
    string parentName, submenuName;

    cout << "Enter parent menu name: ";
    getline(cin, parentName);

    MenuNode* parent = searchMenu(root, parentName);

    if (parent == NULL)
    {
        cout << "Parent menu not found!\n";
        return;
    }

    cout << "Enter new submenu name: ";
    getline(cin, submenuName);

    if (submenuName.empty())
    {
        cout << "Menu name cannot be empty!\n";
        return;
    }

    parent->children.push_back(new MenuNode(submenuName));

    cout << "Submenu added successfully!\n";
}

// Free dynamically allocated memory
void deleteTree(MenuNode* root)
{
    if (root == NULL)
        return;

    for (size_t i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

int main()
{
    // Create the root node
    MenuNode* root = new MenuNode("Website Menu");

    // Create sample menu hierarchy
    root->children.push_back(new MenuNode("Home"));
    root->children.push_back(new MenuNode("About Us"));

    MenuNode* services = new MenuNode("Services");
    services->children.push_back(new MenuNode("Web Development"));
    services->children.push_back(new MenuNode("App Development"));
    services->children.push_back(new MenuNode("SEO"));

    root->children.push_back(services);

    MenuNode* products = new MenuNode("Products");
    products->children.push_back(new MenuNode("Laptops"));
    products->children.push_back(new MenuNode("Mobile Phones"));

    root->children.push_back(products);
    root->children.push_back(new MenuNode("Contact"));

    int choice = 0;

    do
    {
        cout << "\n===== WEBSITE MENU SYSTEM =====\n";
        cout << "1. Display Complete Menu Hierarchy\n";
        cout << "2. Add a Submenu\n";
        cout << "3. Search Menu Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        string input;
        getline(cin, input);

        // Safe input validation for C++98
        bool isValidInt = !input.empty();
        for (size_t i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                isValidInt = false;
                break;
            }
        }

        if (isValidInt)
        {
            choice = atoi(input.c_str());
        }
        else
        {
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                cout << "\nComplete Menu Hierarchy:\n";
                displayMenu(root);
                break;

            case 2:
                addSubmenu(root);
                break;

            case 3:
            {
                string name;
                cout << "Enter menu item to search: ";
                getline(cin, name);

                if (searchMenu(root, name) != NULL)
                    cout << "Menu item found: " << name << endl;
                else
                    cout << "Menu item not found!\n";

                break;
            }

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    deleteTree(root);

    return 0;
}
