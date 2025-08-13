#include <unordered_map>

using namespace std;

class Key {
public:
    string first;
    string second;
    int    third;

    bool operator==(const Key &other) const {
        return first == other.first
            && second == other.second;
    }
};

class KeyHasher {
public:
    size_t operator()(const Key& k) const {
        return hash<string>()(k.first)
               ^ (hash<string>()(k.second) << 1) >> 1;
    }
};

int main() {
    unordered_map<Key,string,KeyHasher> m = {
        { {"John", "Doe", 12}, "example"},
        { {"Mary", "Sue", 21}, "another"}
    };
    Key k = {"John", "Doe", 0};
    cout << k.first << " --> " << m[k] << endl;
    k = {"John", "Elton", 0};
    cout << k.first << " --> " << m[k] << endl;
}
//-------------------------------------------------