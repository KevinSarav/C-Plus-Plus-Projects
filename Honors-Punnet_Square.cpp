#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//list of traits and their mode of autosomal inheritance were used from this website:
//http://faculty.southwest.tn.edu/jiwilliams/human_traits.htm
//for simplicity, all traits used are autosomal and show complete dominance. there are no sex-linked traits or incomplete dominance.
//we also assume the traits do not affect each other's inheritance.
//the average advanced punnett square in a biology class uses 3 traits, which yields only 64 possibilities.
//if you used all 18 traits in the list, there would be 6.87*10^10 possibilities. 

class parents {
	string trait;
	double chance;

public:
	parents() {
		trait = "";
		chance = 0.0;
	}
	parents(string tr, double ch) {
		trait = tr;
		chance = ch;
	}
	double getChance() {
		return chance;
	}
	string getTrait() {
		return trait;
	}
};

string getTrait(char inpy);
void fillParents(parents par[], int &size);
double getChance(string traitt);

int main() {
	ofstream write("out.txt");
	int siz = 0;
	parents *paren = new parents[3];

	fillParents(paren, siz);
	
	write << "Based on your responses for ";
	for (int i = 0; i < siz; i++) {
		if (siz == 1)
			write << paren[i].getTrait() << ": \n";
		else if (i != siz - 1 && siz > 2)
			write << paren[i].getTrait() << ", ";
		else if (i != siz - 1 && siz == 2)
			write << paren[i].getTrait() << " ";
		else
			write << "and " + paren[i].getTrait() << ": \n";
	}
	
	for (int j = 0; j < siz; j++) {
		write << "The chances of the baby having " + paren[j].getTrait() + " are " << paren[j].getChance() << "%. \n";
		if (paren[j].getChance() == 0.0)
			write << "*This probability assumes both of the parents are not heterozygous. \n";
	}

	cin.ignore();
	cin.get();
	return 0;
}

void fillParents(parents par[], int &size) {
	string arry1[18] = { "f = face shape \n", "c = chin \n", "h = hairline \n", "z = eyebrow size \n", "s = eyebrow shape \n",
		"l = eyelash length \n", "d = dimples \n", "o = earlobes \n", "e = eye shape \n", "y = freckles \n", "r = tongue rolling \n",
		"t = tongue folding \n", "m = finger mid-digital hair \n", "k = hitch-hiker's thumb \n", "b = bent little finger \n",
		"i = interlaced fingers \n", "n = hair on back of hand \n", "p = tendoms of palmar muscle \n"};
	string inp, inpy, trait;
	char inpp;
	int count = 18;

	cout << "Would you like to add a trait for the parents?(y/n)";
	cin >> inp;
	cout << "Would you like to use the premade list of traits?(y/n)";
	cin >> inpy;

	while (inp == "y" && count > 0) {
		if (inpy == "y") {
			cout << "What trait would you like to use? \n";
			for (int i = 0; i < count; i++)
				cout << arry1[i];
			cout << "Pick from one of the above: ";
			cin >> inpp;

			for (int i = 0; i < count; i++) {
				if (arry1[i].at(0) == inpp) {
					for (int j = i; j < count - 1; j++)
						arry1[j] = arry1[j + 1];
					par[size] = parents(getTrait(inpp), getChance(getTrait(inpp)));
					size++;
					break;
				}
			}
			count--;
		}

		else {
			cout << "What is the recessive phenotype called?(please describe in one word)";
			cin >> trait;
			par[size] = parents(trait, getChance(trait));
			size++;
		}

		if (count != 0) {
			cout << "Would you like to add another trait?(y/n)";
			cin >> inp;
		}
	}
}

string getTrait(char inpy) {
	string parentTrait, yourTrait, partnerTrait, partParTrait;

	switch (inpy) {						//these are all recessive phenotypes
	case 'f': return "square face";
	case 'c': return "a cleft chin";
	case 'h': return "a straight hairline";
	case 'z': return "slender eyebrows";
	case 's': return "joined eyebrows";
	case 'l': return "short eyelashes";
	case 'd': return "no dimples";
	case 'o': return "an attached earlobe";
	case 'e': return "round shaped eyes";
	case 'y': return "no freckles";
	case 'r': return "can't roll tongue";
	case 't': return "can fold tongue";
	case 'm': return "no mid-digital finger hair";
	case 'k': return "hitch-hiker thumb";
	case 'b': return "straight little finger";
	case 'i': return "right over left interlaced fingers";
	case 'n': return "no hair on back of hand";
	case 'p': return "three tendons of palmar muscle";
	default: return "invalid option";
	}
}

double getChance(string traits) {
	string parentTrait, yourTrait, partnerTrait, partParTrait;

	cout << "Do you have " + traits + "?(y/n)";									//saying yes means that person has a recessive phenotype...
	cin >> yourTrait;															//...while saying no means that person may have a dominant phenotype
	if (yourTrait == "n") {														
		cout << "Do one of your parents have " + traits + "?(y/n)";				
		cin >> parentTrait;
	}
	cout << "Does your partner have " + traits + "?(y/n)";
	cin >> partnerTrait;
	if (partnerTrait == "n") {
		cout << "Does one of your partner's parents have " + traits + "?(y/n)";
		cin >> partParTrait;
	}
																//the below if statements will determine the chances of a baby having a recessive phenotype
	if (yourTrait == "y" && partnerTrait == "y")				//this means both parents are homozygous recessive since recessive phenotypes can't be expressed in heterozygous individuals
		return 100.0;
	else if ((yourTrait == "n" && parentTrait == "y"			//this means one parent is heterozygous since one grandparent is homozygous recessive and the parent doesn't express the recessive phenotype...
		&& partnerTrait == "y") || (yourTrait == "y"			//...while the other parent is homozygous recessive
			&& partnerTrait == "n" && partParTrait == "y"))
		return 50.0;
	else if (yourTrait == "n" && parentTrait == "y"				//this means both parents are heterozygous
		&& partnerTrait == "n" && partParTrait == "y")
		return 25.0;
	else if ((yourTrait == "n" && parentTrait == "n"			//this means both parents are homozygous dominant. this assumes that the grandparents are all homozygous dominant. 
		&& partnerTrait == "n" && partParTrait == "n"))			//there's a chance that both parents may be heterozygous, which would mean the child has a 25% chance of having recessive phenotype
		return 0.0;
	else                                                        //all other possibilities, such as one parent being homozygous recessive and the other showing the dominant phenotype and so are their grandparents...
		return 0.0;												//...means there is no chance the baby will demonstrate the recessive phenotype
}