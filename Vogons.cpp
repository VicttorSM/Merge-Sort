#include <iostream>
#include <cstdlib>

using namespace std;

class Ponto{
	public:
		int x;
		int y;
		Ponto(){
			this->x = 0;
			this->y = 0;
		}
		Ponto(int x, int y){
			this->x = x;
			this->y = y;
		}
};

class Reta{
	private:
		double coef(Ponto P1, Ponto P2){
			if(P1.x==P2.x){
				return 0;
			} else{
				return((P1.y-P2.y)/(P1.x-P2.x));
			}
		}
		int test(Ponto P1, Ponto P2){
			if(P1.x < P2.x) return 0;
			else if(P1.x > P2.x) return 1;
			else if(P1.y > P2.y) return 2;
			else if(P1.y < P2.y) return 3;
			else return 4;
		}
		char sector0(Ponto p){
			if(p.y < (m*p.x - m*this->P1.x + P1.y))
				return 'L';
			else if(p.y > (m*p.x - m*this->P1.x + P1.y))
				return 'O';
			else if(p.y == (m*p.x - m*this->P1.x + P1.y))
				return 'C';
		}
		char sector1(Ponto p){
			if(p.y > (m*p.x - m*this->P1.x + P1.y))
				return 'L';
			else if(p.y < (m*p.x - m*this->P1.x + P1.y))
				return 'O';
			else if(p.y == (m*p.x - m*this->P1.x + P1.y))
				return 'C';
		}
		char sector2(Ponto p){
			if(p.x < this->P1.x)
				return 'L';
			else if(p.x > this->P1.x)
				return 'O';
			else if(p.x == this->P1.x)
				return 'C';
		}
		char sector3(Ponto p){
			if(p.x > this->P1.x)
				return 'L';
			else if(p.x < this->P1.x)
				return 'O';
			else if(p.x == this->P1.x)
				return 'C';
		}
		char sector4(Ponto p){
			if(p.x < this->P1.x)
				return 'L';
			else if(p.x > this->P1.x)
				return 'O';
			else if(p.x == this->P1.x)
				return 'C';
		}
	public:
		Ponto P1;
		Ponto P2;
		double m;
		int caso;
		
		
		Reta(Ponto P1, Ponto P2){
			this->P1 = P1;
			this->P2 = P2;
			this->m = coef(P1, P2);
			this->caso = test(P1, P2);
		}
};

int main(){

	system("pause");
	return 0;
}
