#include <iostream>
#include <string>
using namespace std;

// DIP: high-level NotificationService depends on this abstraction,
// not on a specific email/SMS implementation.
class MessageSender {
public:
    virtual void send(const string& message) const = 0;
    virtual ~MessageSender() = default;
};

class EmailSender : public MessageSender {
public:
    void send(const string& message) const override {
        cout << "Email: " << message << endl;
    }
};

class SmsSender : public MessageSender {
public:
    void send(const string& message) const override {
        cout << "SMS: " << message << endl;
    }
};

class NotificationService {
    const MessageSender& sender;
public:
    explicit NotificationService(const MessageSender& messageSender)
        : sender(messageSender) {}

    void notify(const string& message) const {
        sender.send(message);
    }
};

int main() {
    EmailSender email;
    SmsSender sms;

    NotificationService emailNotification(email);
    NotificationService smsNotification(sms);

    emailNotification.notify("Your order is ready");
    smsNotification.notify("Your order is ready");
    return 0;
}
