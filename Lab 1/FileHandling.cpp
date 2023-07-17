#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Examinee
{
    string id, name, note, hometown;
    float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
        social_science, foreign_language;
};

Examinee readExaminee(string line_info)
{
    stringstream s(line_info);
    Examinee temp;
    string buf;

    getline(s, temp.id, ',');
    getline(s, temp.name, ',');
    getline(s, buf, ',');
    // Get math score
    if (buf == "")
        temp.math = 0;
    else
        temp.math = stoi(buf);
    getline(s, buf, ',');

    // Get literature score
    if (buf == "")
        temp.literature = 0;
    else
        temp.literature = stoi(buf);
    getline(s, buf, ',');

    // Get physic score
    if (buf == "")
        temp.physic = 0;
    else
        temp.physic = stoi(buf);

    // Get chemistry score
    getline(s, buf, ',');
    if (buf == "")
        temp.chemistry = 0;
    else
        temp.chemistry = stoi(buf);

    // Get biology score
    getline(s, buf, ',');
    if (buf == "")
        temp.biology = 0;
    else
        temp.biology = stoi(buf);

    // Get history score
    getline(s, buf, ',');
    if (buf == "")
        temp.history = 0;
    else
        temp.history = stoi(buf);

    // Get geography score
    getline(s, buf, ',');
    if (buf == "")
        temp.geography = 0;
    else
        temp.geography = stoi(buf);

    // Get civic_education score
    getline(s, buf, ',');
    if (buf == "")
        temp.civic_education = 0;
    else
        temp.civic_education = stoi(buf);

    // Get natural_science score
    getline(s, buf, ',');
    if (buf == "")
        temp.natural_science = 0;
    else
        temp.natural_science = stoi(buf);

    // Get social_science score
    getline(s, buf, ',');
    if (buf == "")
        temp.social_science = 0;
    else
        temp.social_science = stoi(buf);

    // Get foreign_language score
    getline(s, buf, ',');
    if (buf == "")
        temp.foreign_language = 0;
    else
        temp.foreign_language = stoi(buf);

    // Get note
    getline(s, temp.note, ',');

    // Get hometown
    getline(s, temp.hometown);
    return temp;
}

vector<Examinee> readExamineeList(string file_name)
{
    ifstream fi(file_name);
    string line_ignore;
    vector<Examinee> examineeList;
    getline(fi, line_ignore, '\n');

    string buf;
    while(!fi.eof())
    {
        getline(fi, buf, '\n');
        examineeList.push_back(readExaminee(buf));
    }
    fi.close();
    return examineeList;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name)
{
    
}

int main()
{
    vector<Examinee> examineeList;
    examineeList = readExamineeList("data.txt");
    for (int i=0;i<examineeList.size();i++)
    {
        cout << examineeList[i].id << " " << examineeList[i].math << endl;
    }
    return 0;
}
