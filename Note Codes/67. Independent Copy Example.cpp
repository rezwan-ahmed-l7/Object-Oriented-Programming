#include <iostream>
using namespace std;

class ScoreCard {
    int* score;

public:
    explicit ScoreCard(int value) : score(new int(value)) {}

    // Each copy owns its own integer.
    ScoreCard(const ScoreCard& other) : score(new int(*other.score)) {}

    ~ScoreCard() {
        delete score;
    }

    void setScore(int value) {
        *score = value;
    }

    int getScore() const {
        return *score;
    }
};

int main() {
    ScoreCard original(85);
    ScoreCard copied = original;

    copied.setScore(100);

    cout << "Original score: " << original.getScore() << endl;
    cout << "Copied score: " << copied.getScore() << endl;

    return 0;
}
