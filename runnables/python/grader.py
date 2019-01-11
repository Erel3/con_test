import sys
from xoractive import guess

MAX_VALUE_OF_N = 100
MAX_VALUE_OF_Q = 200

class Xoractive:
    def __init__(self, n, a):
        self.__n = n
        self.__a = a
        self.__number_of_queries = 0

    def wrong_answer(self, msg):
        print "-1\n"
        sys.exit(0)
    
    def __query(self):
        self.__number_of_queries += 1
        if self.__number_of_queries > MAX_VALUE_OF_Q:
            self.wrong_answer("Number of queries exceeded");

    def get_number_of_queries(self):
        return self.__number_of_queries

    def ask(self, position):
        self.__query()
        if position < 1 or position > n:
            self.__wrong_answer("Not correct position")
        return self.__a[position - 1]
    
    def get_pairwise_xor(self, positions):
        self.__query()
        if len(positions) == 0 or len(positions) > n:
            self.wrong_answer("Not correct size")
        
        positions = list(sorted(positions))
        for i in range(1, len(positions)):
            if positions[i] == positions[i - 1]:
                self.wrong_answer("Not unique")
        for i in range(len(positions)):
            if positions[i] < 1 or positions[i] > n:
                self.wrong_answer("Not correct position")
        
        pairwise_xor = []
        for x in positions:
            for y in positions:
                pairwise_xor.append(self.__a[x - 1]^self.__a[y - 1])
        pairwise_xor = list(sorted(pairwise_xor))
        return pairwise_xor

n = int(raw_input())
a = map(int, raw_input().split())

interactor = Xoractive(n, a)

participant_solution = guess(n, interactor)

if len(participant_solution) != n:
    interactor.wrong_answer("-1")

print len(participant_solution)
print " ".join([str(x) for x in participant_solution])
print interactor.get_number_of_queries()

