//Crispin Bernier, chb2ab, 104


#include "hashTable.h"

using namespace std;

hashTable::hashTable(double l, int si){
  load = l;
  size = getNextPrime( (int)(si*(1.0/l)) );
  hashtable.resize(size);
}

hashTable::~hashTable(){

}

int hashTable::getNextPrime (unsigned int n) {
  while ( !checkprime(++n) );
  return n; // all your primes are belong to us
}

bool hashTable::checkprime(unsigned int p) {
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
    return false;
  if ( p == 2 ) // 2 is prime
    return true;
  if ( p % 2 == 0 ) // even numbers other than 2 are not prime
    return false;
  for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
    if ( p % i == 0 )
      return false;
  return true;
}

void hashTable::insert(string word) {
  int count = 0;
  int iterator = 0;
  while (iterator < word.size()){
    count += word[iterator]*(37^iterator);
    iterator++;
  }
  hashtable[count%size].insert(word);
}

bool hashTable::search(string s){
  int count = 0;
  int it = 0;
  while (it < s.size()){
    count += s[it]*(37^it);
    it++;
  }
  AvlTree search = hashtable[count%size];
  if (search.isEmpty())
    return false;
  if (search.find(s))
    return true;
  else return false;
}
