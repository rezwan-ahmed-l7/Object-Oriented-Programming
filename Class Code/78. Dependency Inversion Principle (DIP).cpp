#include <iostream>
using namespace std;

// High-level Notification depends on an abstraction, not a concrete sender.
class MessageSender {
public:
    virtual ~MessageSender() = default;
    virtual void send(const char* message) const = 0;
};

class ConsoleSender : public MessageSender {
public:
    void send(const char* message) const override {
        cout << "Notification: " << message << endl;
    }
};

class Notification {
    const MessageSender& sender;
public:
    explicit Notification(const MessageSender& messageSender) : sender(messageSender) {}
    void alert(const char* message) const {
        sender.send(message);
    }
};

int main() {
    ConsoleSender sender;
    Notification notification(sender);
    notification.alert("Your order is ready.");
    return 0;
}