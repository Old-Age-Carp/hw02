#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// animal 클래스 정의
class animal {
public:
	virtual void makesound() = 0;
	virtual ~animal() {
		
	}
};

// 서브 클래스
class dog : public animal {
public:
	void makesound() override {
		std::cout << "멍" << std::endl;
	}
	~dog() override {
		std::cout << "강아지" << std::endl;
	}
};

class cat : public animal {
public:
	void makesound() override {
		std::cout << "냥" << std::endl;
	}
	~cat() override {
		std::cout << "고양이" << std::endl;
	}
};

class cow : public animal {
public:
	void makesound() override {
		std::cout << "음메" << std::endl;
	}
	~cow() override {
		std::cout << "소" << std::endl;
	}
};

// 랜덤 함수
animal* createrandomanimal() {
	int randomnum = rand() % 3;
	if (randomnum == 0) {
		return new dog();
	} else if (randomnum == 1) {
		return new cat();
	} else {
		return new cow();
	}
}

// zoo 클래스
class zoo {
private:
	animal* animals[10];
	int animalcount;

public:
	zoo() : animalcount(0) {
		for (int i = 0; i < 10; ++i) {
			animals[i] = nullptr;
		}
		std::cout << "동물원" << std::endl;
	}

	void addanimal(animal* animal) {
		if (animalcount < 10) {
			animals[animalcount] = animal;
			animalcount++;
			std::cout << "동물 추가, 현재 동물 수: " << animalcount << "마리" << std::endl;
		}
		else {
			std::cout << "동물원이 꽉 찼습니다. 더 이상 추가할 수 없습니다." << std::endl;
			delete animal;
		}
	}

	void performactions() {
		std::cout << "---------- 동물들 행동 시작 ----------" << std::endl;
		if (animalcount == 0) {
			std::cout << "동물원에 남은 동물이 없습니다." << std::endl;
			return;
		}
		for (int i = 0; i < animalcount; ++i) {
			std::cout << (i + 1) << "번째 동물: ";
			animals[i]->makesound();
			std::cout << "-------------------------" << std::endl;
		}
		std::cout << "---------- 동물들 행동 종료 ----------" << std::endl;
	}

	~zoo() {
		std::cout << "호출된 동물은 우리로 돌아가시오" << std::endl;
		for (int i = 0; i < animalcount; ++i) {
			if (animals[i] != nullptr) {
				delete animals[i];
				animals[i] = nullptr;
			}
		}
		std::cout << "모든 동물 복귀 완료" << std::endl;
	}
};

// 구동 시작 지점
int main() {
	srand(static_cast<unsigned int>(time(0)));

	std::cout << "동물원 동물 순서대로 울기 시작" << std::endl;
	animal* animalsinmain[3];

	dog mydog;
	cat mycat;
	cow mycow;

	animalsinmain[0] = &mydog;
	animalsinmain[1] = &mycat;
	animalsinmain[2] = &mycow;

	std::cout << "울음 소리: " << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << (i + 1) << "번째 동물: ";
		animalsinmain[i]->makesound();
	}
std::cout << "울기 종료" << std::endl;

	std::cout << "랜덤 울기 시작" << std::endl;
	zoo myzoo;
	for (int i = 0; i < 5; ++i) {
		animal* newanimal = createrandomanimal();
		myzoo.addanimal(newanimal);
	}

	myzoo.performactions();

	std::cout << "끝" << std::endl;

	return 0;
}