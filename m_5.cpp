/*Imagine you are building a social networking application where users can connect with each other 
as friends. You need to create a User class to represent each user and allow users to become 
friends with each other. To implement this, you should use a friend function to establish a 
friendship connection between two User objects.*/

#include <iostream>
#include <string>
#include <vector>

class User; // Forward declaration

class FriendManager {
public:
    // Friend function to establish a friendship connection between two users
    friend void makeFriends(User& user1, User& user2);
};

class User {
private:
    std::string username;
    std::vector<User> friends;

public:
    User(const std::string& name) : username(name) {}

    // Method to display the user's friends
    void displayFriends() {
        std::cout << "Friends of " << username << ": ";
        for (const User& friendUser : friends) {
            std::cout << friendUser.username << " ";
        }
        std::cout << std::endl;
    }

    // Allow the FriendManager class to access the User's private members
    friend void makeFriends(User& user1, User& user2);
};

// Friend function definition to establish friendship
void makeFriends(User& user1, User& user2) {
    user1.friends.push_back(user2);
    user2.friends.push_back(user1);
}

int main() {
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");

    // Alice and Bob become friends
    makeFriends(alice, bob);

    // Bob and Charlie become friends
    makeFriends(bob, charlie);

    alice.displayFriends(); // Alice's friends: Bob
    bob.displayFriends();   // Bob's friends: Alice, Charlie
    charlie.displayFriends(); // Charlie's friends: Bob

    return 0;
}



