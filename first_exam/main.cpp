//
//  main.cpp
//  oop_exam
//
//  Created by Emil Iliev on 3/30/18.
//  Copyright © 2018 Emil Iliev. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX_AGE 300
#define SKILL_CAPACITY 15

class Elf {
  
    char* name;
    int age;
    int skill;
    
    void copyFrom(const Elf& other) {
        setName(other.getName());
        setAge(other.getAge());
        setSkills(other.getSKills());
    }
    
    public:
    
    Elf():age(1),skill(1) {
        name = new char[1];
        strcpy(name,"\0");
    }
    
    Elf(char* _name, int _age, int _skill): name(nullptr) {
        setName(_name);
        setAge(_age);
        setSkills(_skill);
    }
    
    Elf(const Elf& other): name(nullptr){
        copyFrom(other);
    }
    
    Elf& operator=(const Elf& other) {
        if (this != &other) {
            copyFrom(other);
        }
        
        return *this;
    }
    
    ~Elf() {
        delete [] name;
    }
    
    void setName(char* _name) {
//        if (_name) {
            delete [] name;
            int lenght = strlen(_name) + 1;
            name = new char[lenght];
            strcpy(name, _name);
//        }
    }
    
    void setAge(int newAge) {
        if (newAge >= 0 && newAge < MAX_AGE) {
            age = newAge;
        }
        else {
            cout<<"wrong number\n";
        }
    }
    
    void setSkills(int _skils) {
        if (_skils >= 1 && _skils <= SKILL_CAPACITY){
            skill = _skils;
        } else {
            cout<<"Wrong digit for skillszzz\n";
        }
    }
  
    char* getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
    
    int getSKills() const {
        return skill;
    }
  
    bool operator==(const Elf& other) {
        return strcmp(this->name, other.name) && this->age == other.age && this->skill == other.skill;
    }
    
    friend ostream& operator<<(ostream& output, Elf& elf) {
        output<<elf.getName()<<" "<<elf.age<<" "<<elf.skill<<endl;
        return output;
    }
    
};


class ElfTeam {
    
    char teamName[30];
    Elf elfs[50];
    
    int numElfs;
    
    int getTeamAge() {
        int totalAge = 0;
        for(int index = 0; index < numElfs; ++index) {
            totalAge += elfs[index].getAge();
        }
        
        return totalAge;
    }
    
    int getTeamSkills() {
        int totalSkillsCount = 0;
        for(int index = 0; index < numElfs; ++index) {
            totalSkillsCount += elfs[index].getSKills();
        }
    
        return totalSkillsCount;
    }
    
    public:

    ElfTeam() {
        numElfs = 0;
    }
    
    void setTeamName(char* _name) {
        if (strlen(_name) < 30) {
            strcpy(teamName, _name);
        }
    }
    
    void addElf(const Elf& elf){
        if (numElfs < 50) {
            elfs[numElfs++] = elf;
        }
    }
    
    Elf getElf(int index) {
        if (numElfs > index && index > 0) {
            return elfs[index];
        }
        return Elf();
    }
    
    bool operator<(ElfTeam& bTeam) {
        return this->getRatio() < bTeam.getRatio();
    }
    
    double getRatio()  {
        return getTeamAge() / getTeamSkills();
    }
    
    
    ElfTeam operator+(ElfTeam& otherTeam) {
        ElfTeam team;
        
        for(int index = 0; index < this->numElfs; ++index) {
            team.addElf(this->getElf(index));
        }
        
        for(int index = 0; index < otherTeam.numElfs; ++index) {
            Elf currentElf = otherTeam.getElf(index);
            if (!compareElfs(currentElf)){
                team.addElf(currentElf);
            }
        }
        
        team.setTeamName(this->teamName);
        return team;
    }
    
    bool compareElfs(const Elf& currentElf) {
        for(int index = 0; index < numElfs; ++index) {
            if (elfs[index] == currentElf) {
                return true;
            }
        }
        return false;
    }
    
    ElfTeam& operator+=( ElfTeam& otherTeam) {
        
        for(int index = 0; index < otherTeam.numElfs; ++index) {
            Elf currentElf = otherTeam.getElf(index);
            if (!compareElfs(currentElf)){
                addElf(currentElf);
            }
        }
        
        return *this;
    }
    
    int getNumElfs() const {
        return numElfs;
    }
    
    int teamSkills() const {
        int totalTeamSkills = 0;
        for(int index = 0; index < numElfs; ++index) {
            totalTeamSkills += elfs[index].getSKills();
        }
        return totalTeamSkills;
    }
    
    void printTeam() {
        for(int index = 0 ; index < numElfs; ++index) {
            cout<<elfs[index]<<endl;
        }
    }
};


void analyise(ElfTeam* teams, int numTeams) {
    int mostSkilledTeam = 0; // team index
    int curTeamSkills = teams[mostSkilledTeam].teamSkills();
    
    for(int index = 1; index < numTeams; ++index) {
        if (curTeamSkills < teams[index].teamSkills()) {
            mostSkilledTeam = index;
            curTeamSkills = teams[index].teamSkills();
        }
    }
    
    teams[mostSkilledTeam].printTeam();
}

int main(int argc, const char * argv[]) {
    
    Elf darko("Penka", 256, 10);
    Elf darko1("Darko", 257, 11);
    Elf darko2("Kiro", 258, 12);
    Elf darko3("Darko", 259, 13);
    Elf darko4("Pesho", 260, 14);
    
    ElfTeam team1;//34
    
    team1.addElf(darko);
    team1.addElf(darko1);
    team1.addElf(darko3);
    
    
    ElfTeam team2; //36
    
    team2.addElf(darko);
    team2.addElf(darko2);
    team2.addElf(darko4);
    
    
    ElfTeam teams[2] = {team1, team2};
    
    analyise(teams, 2);
    
    return 0;
}
