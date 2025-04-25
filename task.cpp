#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Задание 1
void task1(vector<double>& v, double a) {
    if (v.empty()) return;
    
    for (auto& elem : v) elem *= 2;
    for (auto& elem : v) elem -= a;
    
    double first = v[0];
    if (first != 0) {
        for (auto& elem : v) elem /= first;
    }
}

// Задание 2
void task2(const vector<int>& v) {
    if (v.empty()) return;
    
    int sum = 0;
    for (int num : v) sum += num;
    cout << sum << endl;
    
    int sum_sq = 0;
    for (int num : v) sum_sq += num * num;
    cout << sum_sq << endl;
    
    int sum6 = 0;
    for (int i = 0; i < 6 && i < v.size(); i++) sum6 += v[i];
    cout << sum6 << endl;
    
    int k1, k2;
    cin >> k1 >> k2;
    if (k1 >= 0 && k2 < v.size() && k2 > k1) {
        int sum_k = 0;
        for (int i = k1; i <= k2; i++) sum_k += v[i];
        cout << sum_k << endl;
    }
    
    cout << (double)sum / v.size() << endl;
    
    int s1, s2;
    cin >> s1 >> s2;
    if (s1 >= 0 && s2 < v.size() && s2 > s1) {
        int sum_s = 0;
        for (int i = s1; i <= s2; i++) sum_s += v[i];
        cout << (double)sum_s / (s2 - s1 + 1) << endl;
    }
}

// Задание 3
void task3(vector<int>& v) {
    if (v.size() < 6) return;
    
    for (int i = 0; i < 3; i++) {
        swap(v[i], v[v.size() - 3 + i]);
    }
}

// Задание 4
void task4(vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            v.erase(v.begin() + i);
            break;
        }
    }
    
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] % 2 == 0) {
            v.erase(v.begin() + i);
            break;
        }
    }
}

// Задание 5
void task5(const string& city) {
    cout << (city.length() % 2 == 0 ? "Even" : "Odd") << endl;
}

// Задание 6
void task6(const string& s1, const string& s2) {
    cout << (s1.length() > s2.length() ? s1 : s2) << endl;
}

// Задание 7
void task7(const string& c1, const string& c2, const string& c3) {
    string longest = c1, shortest = c1;
    if (c2.length() > longest.length()) longest = c2;
    if (c3.length() > longest.length()) longest = c3;
    if (c2.length() < shortest.length()) shortest = c2;
    if (c3.length() < shortest.length()) shortest = c3;
    cout << longest << " " << shortest << endl;
}

// Задание 8
void task8(const string& word, int m, int n) {
    if (m >= 0 && n < word.length() && m <= n) {
        cout << word.substr(m, n - m + 1) << endl;
    }
}

// Задание 9
void task9(string& word) {
    string stars(word.length(), '*');
    word = stars + word + stars;
    cout << word << endl;
}

// Задание 10
void task10(const string& sentence) {
    int count = 0;
    for (char c : sentence) if (c == 'a') count++;
    cout << (double)count / sentence.length() * 100 << endl;
}

// Задание 11
void task11(string& sentence, const string& newWord) {
    size_t pos = 0;
    while ((pos = sentence.find("can", pos)) != string::npos) {
        sentence.replace(pos, 3, newWord);
        pos += newWord.length();
    }
    cout << sentence << endl;
}

int main() {
    // Примеры вызовов функций
    vector<double> v1 = {1.5, 2.0, 3.5};
    task1(v1, 1.0);
    
    vector<int> v2 = {1, 2, 3, 4, 5};
    task2(v2);
    
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    task3(v3);
    
    vector<int> v4 = {1, -2, 3, 4, -5};
    task4(v4);
    
    task5("Moscow");
    task6("Ivanov", "Petrov");
    task7("Paris", "London", "Berlin");
    task8("Programming", 3, 7);
    
    string word = "Hello";
    task9(word);
    
    string sentence = "Can you can a can as a canner can can a can?";
    task10(sentence);
    task11(sentence, "newWord");
    
    return 0;
}
