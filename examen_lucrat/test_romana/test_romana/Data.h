//
// Created by kida on 5/23/21.
//

#ifndef TEST_ROMANA_DATA_H
#define TEST_ROMANA_DATA_H


class Data {
private:
    int month;
    int day;
public:
    Data() = default;

    Data(int month, int day);

    [[nodiscard]] int getMonth() const;

    [[nodiscard]] int getDay() const;

    std::string to_string() const;

};


#endif //TEST_ROMANA_DATA_H
