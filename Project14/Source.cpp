#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;
class CommunityMember {
	unsigned long int ID;
	string FirstName;
	string LastName;
	string Address;
	unsigned long int CellPhone;
public:
	CommunityMember() {}
	CommunityMember(unsigned long int id, string fn, string ln, string addr, unsigned long int cp) {
		ID = id;
		FirstName = fn;
		LastName = ln;
		Address = addr;
		CellPhone = cp;
	}
	void setID(unsigned long int id) {
		ID = id;
	}
	unsigned long int getID() const {
		return ID;
	}
	void setFirstName(string fn) {
		FirstName = fn;
	}
	string getFirstName() const {
		return FirstName;
	}
	void setLastName(string ln) {
		LastName = ln;
	}

	string getLastName() {
		return LastName;
	}
	void setAddress(string addr) {
		Address = addr;
	}

	string getAddress() {
		return Address;
	}

	void setCellPhone(unsigned long int cp) {
		CellPhone = cp;
	}

	unsigned long int getCellPhone() {
		return CellPhone;
	}
	virtual void ReadData() {
		unsigned long int id;
		string fn;
		string ln;
		string addr;
		unsigned long int cp;
		cout << "\nID: ";
		cin >> id;
		cout << "\nFirstName: ";
		cin >> fn;
		cout << "\nLastName: ";
		cin >> ln;
		cout << "\nAddress: ";
		cin >> addr;
		cout << "\nCellPhone: ";
		cin >> cp;
		setID(id);
		setFirstName(fn);
		setLastName(ln);
		setAddress(addr);
		setCellPhone(cp);
	}

	virtual void Print() {
		cout << "\nID: " << getID();
		cout << "\nFirstName: " << getFirstName();
		cout << "\nLastName: " << getLastName();
		cout << "\nAddress: " << getAddress();
		cout << "\nCellPhone: " << getCellPhone();
	}
};


class Student : public CommunityMember {
private:
	double GPA;
	unsigned int CourseLoadHours;
public:
	Student() : CommunityMember() {
		GPA = 0.0;
		CourseLoadHours = 0;
	}
	Student(unsigned long int id, string fn, string ln, const string addr, unsigned long int cp, double gpa, unsigned int clh) : CommunityMember(id, fn, ln, addr, cp) {
		GPA = gpa;
		CourseLoadHours = clh;
	}
	void setGPA(double gpa) {
		GPA = gpa;
	}
	double getGPA() const {
		return GPA;
	}
	void setCourseLoadHours(unsigned int clh) {
		CourseLoadHours = clh;
	}
	unsigned int getCourseLoadHours()const {
		return CourseLoadHours;
	}
	void ReadData() {
		double gpa;
		unsigned int clh;
		CommunityMember::ReadData();
		cout << "\nGPA: ";
		cin >> gpa;
		cout << "\nCourse Load Hours: ";
		cin >> clh;
		setGPA(gpa);
		setCourseLoadHours(clh);
	}
	void Print() {
		CommunityMember::Print();
		cout << "\nGPA: " << getGPA();
		cout << "\nCourse Load Hours: " << getCourseLoadHours();
	}
};

class Alumnus : public CommunityMember {
private:
	unsigned int YearOfGraduation;
	string CurrentJob;
public:
	Alumnus() :CommunityMember() {
		YearOfGraduation = 0;
		CurrentJob = "";
	}
	Alumnus(unsigned long int id, string fn, string ln, string addr, unsigned long int cp, unsigned int yog, string cj) :CommunityMember(id, fn, ln, addr, cp) {
		YearOfGraduation = yog;
		CurrentJob = cj;
	}
	void setYearOfGraduation(unsigned int yog) {
		YearOfGraduation = yog;
	}
	unsigned int getYearOfGraduation()const {
		return YearOfGraduation;
	}
	void setCurrentJob(string cj) {
		CurrentJob = cj;
	}
	string getCurrentJob() const {
		return CurrentJob;
	}
	void ReadData() {
		unsigned int yog;
		string cj;
		CommunityMember::ReadData();
		cout << "\nYear of Graduation: ";
		cin >> yog;
		cout << "\nCurrent Job: ";
		cin >> cj;
		setYearOfGraduation(yog);
		setCurrentJob(cj);
	}
	void Print() {
		CommunityMember::Print();
		cout << "\nYear of Graduation: " << getYearOfGraduation();
		cout << "\nCurrent Job: " << getCurrentJob();
	}
};

class Employee : public CommunityMember {
private:
	double Salary;

public:
	Employee() {

	}

	Employee(unsigned long int id, string fn, string ln, string addr, unsigned long int cp, double sal) : CommunityMember(id, fn, ln, addr, cp) {
		Salary = sal;
	}

	void setSalary(double sal) {
		Salary = sal;
	}

	double getSalary() {
		return Salary;
	}

	void ReadData() {
		double sal;

		CommunityMember::ReadData();
		cout << "\nSalary: "; cin >> sal;

		setSalary(sal);
	}

	void Print() {
		CommunityMember::Print();
		cout << "\nSalary: " << getSalary();

	}
};
class Faculty : public Employee {
private:
	string Speciality;
	string AcademicRank;

public:
	Faculty() {

	}

	Faculty(unsigned long int id, string fn, string ln, string addr, unsigned long int cp, double sal, string splty, string acdrnk) :Employee(id, fn, ln, addr, cp, sal) {
		Speciality = splty;
		AcademicRank = acdrnk;
	}

	void setSpeciality(string splty) {
		Speciality = splty;
	}

	string getSpeciality() {
		return Speciality;
	}

	void setAcademicRank(string acdrnk) {
		AcademicRank = acdrnk;
	}

	string getAcademicRank() {
		return AcademicRank;
	}

	void ReadData() {
		string splty;
		string acdrnk;

		Employee::ReadData();
		cout << "\nSpeciality: "; cin >> splty;
		cout << "\nAcademic Rank: "; cin >> acdrnk;

		setSpeciality(splty);
		setAcademicRank(acdrnk);
	}

	void Print() {
		Employee::Print();
		cout << "\nSpeciality: " << getSpeciality();
		cout << "\nAcademic Rank: " << getAcademicRank();
	}
};


class Staff : public Employee {
private:
	string Department;
public:
	Staff() :Employee() {
		Department = "";
	}
	Staff(unsigned long int id, string fn, string ln, string addr, unsigned long int cp, double sal, string dept) :Employee(id, fn, ln, addr, cp, sal) {
		Department = dept;
	}
	void setDepartment(string dept) {
		Department = dept;
	}
	string getDepartment()const {
		return Department;
	}
	void ReadData() {
		string dept;
		Employee::ReadData();
		cout << "\nDepartment: "; cin >> dept;
		setDepartment(dept);
	}
	void Print() {
		Employee::Print();
		cout << "\nDepartment: " << getDepartment();
	}
};

class Administrator : public Faculty {
private:
	int accountnum;
	string Position;
public:
	Administrator() : Faculty() {
		Position = "";
		accountnum = 0;
	}
	Administrator(unsigned long int id, string fn, string ln, string addr, unsigned long int cp, double sal, string splty, string acdrnk, string pos, int accn) : Faculty(id, fn, ln, addr, cp, sal, splty, acdrnk) {
		Position = pos;
		accountnum = accn;
	}
	void setaccountnum(int accn) {
		accountnum = accn;
	}
	int getaccountnum()const {
		return accountnum;
	}
	void setPosition(string pos) {
		Position = pos;

	}
	string getPosition()const {
		return Position;
	}
	void ReadData() {
		string pos;
		Employee::ReadData();
		cout << "\nPosition: "; cin >> pos;
		setPosition(pos);
	}
	void Print() {
		Employee::Print();
		cout << "\nPosition: " << getPosition();
	}
	void printToFile() {
		int accountNum;
		unsigned long int id, cp;
		string fn, ln, addr, splty, acdrnk, pos;
		double sal;
		fstream outcredit;
		outcredit.open("community.dat", ios::out | ios::binary);
		if (!outcredit) {
			cerr << "file could not open" << endl;
			exit(EXIT_FAILURE);
		}
		// cout << "enter account number(1 to 100, 0to end input)\n?";
	  //   cin >> accountNum;
		Administrator one;
		do {
			cout << "enter account number\n?";
			cin >> accountNum;
			cout << "enter id, first name, last name, address, cell phone, salary, speciality, academicrank, position in the same order please!\n?";
			cin >> id >> fn >> ln >> addr >> cp >> sal >> splty >> acdrnk >> pos;
			one.setaccountnum(accountNum);
			one.setID(id);
			one.setFirstName(fn);
			one.setLastName(ln);
			one.setAddress(addr);
			one.setCellPhone(cp);
			one.setSalary(sal);
			one.setSpeciality(splty);
			one.setAcademicRank(acdrnk);
			one.setPosition(pos);
			outcredit.seekp((one.getaccountnum() - 1) * sizeof(Administrator));
			outcredit.write(reinterpret_cast<const char*>(&one), sizeof(Administrator));

		} while (!(accountNum > 0 && accountNum <= 100));
	}
	void readFromFile() {
		ifstream incredit;
		incredit.open("community.dat", ios::binary | ios::in);
		if (!incredit) {
			cerr << "file could not be open" << endl;
			exit(EXIT_FAILURE);
		}
		cout << left << setw(10) << "Account" << right << setw(10) << "ID" << right << setw(10) << "First Name" << right << setw(10) << "Last Name" << right << setw(10) << "Address" << right << setw(10) << "Cell Phone" << right << setw(10) << "Salary" << right << setw(10) << "Speciality" << right << setw(10) << "Academic Rank" << right << setw(10) << "Position" << endl;
		Administrator one;
		incredit.read(reinterpret_cast<char*>(&one), sizeof(Administrator));
		while (incredit && !incredit.eof()) {
			if (one.getaccountnum() != 0)
				outputline(cout, one);
			incredit.read(reinterpret_cast<char*>(&one), sizeof(Administrator));
		}
	}
	void outputline(ostream& output, Administrator& r) {
		output << left << setw(10) << r.getaccountnum() << right << setw(10) << r.getID() << right << setw(10) << r.getFirstName() << right << setw(10) << r.getLastName() << right << setw(10) << r.getAddress() << right << setw(10) << r.getCellPhone() << right << setw(10) << setprecision(2) << fixed << showpoint << r.getSalary() << right << setw(10) << r.getSpeciality() << right << setw(10) << r.getAcademicRank() << right << setw(10) << r.getPosition() << endl;
	}
};

class Teacher : public Faculty {
private:
	int accountnum;
	unsigned int HoursPerWeek;

public:
	Teacher() : Faculty() {
		HoursPerWeek = 0;
		accountnum = 0;
	}

	Teacher(unsigned long int id, string fn, string ln, string addr, unsigned long int cp, double sal, string splty, string acdrnk, unsigned int hpw, int accn) : Faculty(id, fn, ln, addr, cp, sal, splty, acdrnk) {
		HoursPerWeek = hpw;
		accountnum = accn;
	}
	void setaccountnum(int accn) {
		accountnum = accn;
	}
	int getaccountnum() const {
		return accountnum;
	}
	void setHoursPerWeek(unsigned int hpw) {
		HoursPerWeek = hpw;
	}

	unsigned int getHoursPerWeek() const {
		return HoursPerWeek;
	}

	void ReadData() {
		unsigned int hpw;
		Faculty::ReadData();

		cout << "\nHours Per Week: "; cin >> hpw;
		setHoursPerWeek(hpw);
	}

	void Print() {
		Faculty::Print();
		cout << "\nHours Per Week: " << getHoursPerWeek();
	}
	/*void printToFile() {
		int accountNum;
		unsigned long int id, cp, hpw;
		string fn, ln, addr, splty, acdrnk;
		double sal;
		fstream outcredit("community.dat",  ios::out | ios::binary);
		if (!outcredit) {
		  cerr << "file could not open" << endl;
		  exit(EXIT_FAILURE);
		}
		cout << "enter account number(1 to 100, 0to end input)\n?";
		cin >> accountNum;
		Teacher one;
		do {
		  cout << "enter account number\n?";
		  cin >> accountNum;
		  cout << "enter id, first name, last name, address, cell phone, salary, speciality, academicrank, hours per week in the same order please!\n?";
		  cin >> id >> fn >> ln >> addr >> cp >> sal >> splty >> acdrnk >> hpw;
		  one.setaccountnum(accountNum);
		  one.setID(id);
		  one.setFirstName(fn);
		  one.setLastName(ln);
		  one.setAddress(addr);
		  one.setCellPhone(cp);
		  one.setSalary(sal);
		  one.setSpeciality(splty);
		  one.setAcademicRank(acdrnk);
		  one.setHoursPerWeek(hpw);
		  outcredit.seekp((one.getaccountnum() - 1) * sizeof(Teacher));
		  outcredit.write(reinterpret_cast<const char*>(&one), sizeof(Teacher));

		} while (!(accountNum > 0 && accountNum <= 100));
	  }
		void readFromFile(){
			ifstream incredit("community.dat", ios::binary| ios::in);
			if (!incredit){
				cerr<<"file could not be open"<<endl;
				exit(EXIT_FAILURE);
			}
				cout<<left<<setw(10)<<"Account"<<right<<setw(10)<<"ID"<<right<<setw(10)<<"First Name"<<right<<setw(10)<<"Last Name"<<right<<setw(10)<<"Address"<<right<<setw(10)<<"Cell Phone"<<right<<setw(10)<<"Salary"<<right<<setw(10)<<"Speciality"<<right<<setw(10)<<"Academic Rank"<<right<<setw(10)<<"Hour per week"<<endl;
				Teacher one;
				incredit.read(reinterpret_cast<char*>(&one),sizeof(Teacher));
				while(incredit&&!incredit.eof() ){
					if(one.getaccountnum()!=0)
					outputline(cout, one);
				incredit.read(reinterpret_cast<char*>(&one),sizeof(Teacher));
			}
		}
		void outputline(ostream &output,   Teacher &r){
			output<<left<<setw(10)<<r.getaccountnum()<<right<<setw(10)<<r.getFirstName()<<right<<setw(10)<<r.getLastName()<<right<<setw(10)<<r.getAddress()<<right<<setw(10)<<r.getCellPhone()<<right<<setw(10)<<setprecision(2)<<fixed<<showpoint<<r.getSalary()<<right<<setw(10)<<r.getSpeciality()<<right<<setw(10)<<r.getAcademicRank()<<right<<setw(10)<<r.getHoursPerWeek()<<endl;
		}*/
};
int main() {
	/*Teacher show1;*/
	Administrator show2;
	/*	show1.ReadData();
		cout<<endl;
		show1.Print();
		cout<<endl;
		show1.printToFile();
		cout<<endl;
		show1.readFromFile();
		cout<<endl; */
	show2.ReadData();
	cout << endl;
	show2.Print();
	cout << endl;
	show2.printToFile();
	cout << endl;
	show2.readFromFile();
	cout << endl;
	return 0;
}

