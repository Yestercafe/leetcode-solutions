constexpr int CAT = 0;
constexpr int DOG = 1;

class AnimalShelf {
    deque<int> cats, dogs;
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        switch (animal[1]) {
            case CAT:
                cats.push_back(animal[0]);
                dogs.push_back(-1);
                break;
            case DOG:
                dogs.push_back(animal[0]);
                cats.push_back(-1);
                break;
        }
    }
    
    vector<int> dequeueAny() {
        while (!cats.empty() && cats.front() < 0) {
            cats.pop_front();
        }
        while (!dogs.empty() && dogs.front() < 0) {
            dogs.pop_front();
        }

        if (cats.empty() && dogs.empty()) return {-1, -1};
        
        if (cats.size() > dogs.size()) {
            auto f = cats.front();
            cats.pop_front();
            return {f, CAT};
        } else {
            auto f = dogs.front();
            dogs.pop_front();
            return {f, DOG};
        }
    }
    
    vector<int> dequeueDog() {
        while (!dogs.empty() && dogs.front() < 0) {
            dogs.pop_front();
        }

        if (dogs.empty()) return {-1, -1};

        auto f = dogs.front();
        dogs.pop_front();
        return {f, DOG};
    }
    
    vector<int> dequeueCat() {
        while (!cats.empty() && cats.front() < 0) {
            cats.pop_front();
        }

        if (cats.empty()) return {-1, -1};
        auto f = cats.front();
        cats.pop_front();
        return {f, CAT};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */

