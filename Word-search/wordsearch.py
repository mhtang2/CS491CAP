import random
import string

N = 15
n_words = 2
p_reverse = 1.0

corpus = set()
with open("oxford5000.txt",'r') as fp:
    for s in fp:
        s = s.strip()
        if 4<=len(s)<=6:
            corpus.add(s.upper())
print(f"Loaded {len(corpus)} words")

def get_row():
    words_og = random.sample(list(corpus),n_words)
    words = list(words_og)
    # random reverse
    for i in range(len(words)):
        if random.random() < p_reverse:
            words[i] = words[i][::-1]

    length = N - sum([len(x) for x in words])
    result = ''.join(random.choice(string.ascii_uppercase) for _ in range(length))

    # random injection
    length = len(result)
    start_pos = 0
    for string_to_inject in words:
        # Choose a random position to insert the string
        insert_position = random.randint(start_pos, length)

        start_pos = len(string_to_inject) + insert_position

        # Insert the string into the result at the chosen position
        result = result[:insert_position] + string_to_inject + result[insert_position:]
        
        # Update the length of the result string
        length = len(result)
    return result, words_og

# string printing
def h_print(s):
    for c in s:
        print(c,end=" ")

def v_print(s):
    for c in s:
        print(c,end="\n")

print()
print_fn = h_print
while True:
    s, words = get_row()
    print_fn(s)
    print()
    inp = input()

   
    print(f"Words: {' '.join(words)}")
    print()
    if inp=='e':
        break
    if inp=='h':
        print_fn = h_print
    if inp=='v':
        print_fn = v_print
        


            