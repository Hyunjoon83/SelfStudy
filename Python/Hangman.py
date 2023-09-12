import random
HANGMAN_PICS = [
    '''
    +---+
    |   |
        |
        |
       ===   ,   
    ''',
    '''
    +---+
    O   |
        |
        |
       ===   ,   
    ''',
    '''
    +---+
    O   |
    |   |
        |
       ===   ,   
    ''',
    '''
    +---+
    O   |
   /|   |
        |
       ===   ,   
    ''',
    '''
    +---+
    O   |
   /|\  |
        |
       ===   ,   
    ''',
    '''
    +---+
    O   |
   /|\  |
   /    |
       ===   ,   
    ''',
    '''
    +---+
    O   |
   /|\  |
   / \  |
       ===  ,   
    '''
]

words='ant baboon badger bat bear beaver camel cat clam cobra couger\
    coyote crow deer dog donkey duck eagle ferret fox frog goat goose hawk\
    lion lizard llama mole monkey moose mouse mule newt otter owl panda\
    parrot pigeon python rabbit ram rat raven rhino salmon seal shark sheep\
    skunk sloth snake spider stork swan tiger toad trout turkey turtle weasel\
    whale wolf wombat zebra'.split()
    
def getRandomWord(wordList):
    wordIndex=random.randint(0,len(wordList)-1)
    return wordList[wordIndex]

def displayBoard(missedLetters, correctLetters, secretWord):
    print(HANGMAN_PICS[len(missedLetters)])
    print()
    
    print("Missed letters: ",end=' ')
    for letter in missedLetters:
        print(letter,end=' ')
    print()
    
    blank="_"*len(secretWord)
    
    for i in range(len(secretWord)):
        if secretWord[i] in correctLetters:
            blank=blank[:i]+secretWord[i]+blank[i+1:]
    
    for letter in blank:
        print(letter,end=' ')
    print()
    
def getGuess(alreadyGuessed):
    while True:
        print("Guess a letter")
        guess=input()
        guess=guess.lower()
        if len(guess)!=1:
            print("Please enter a single letter.")
        elif guess in alreadyGuessed:
            print("You have already guessed that letter. Choose again.")
        elif guess not in 'abcdefghijklmmnopqrstuvwxyz':
            print("Please enter a LETTER.")
        else:
            return guess
def playAgain():
    print("Do you want to play again?  (yes or no)")
    return input().lower().startswith('y')

print("H A N G M A N")
missedLetters =''
correctLetters =''
secretWord = getRandomWord(words)
gamesDone = False

while True:
    displayBoard(missedLetters,correctLetters,secretWord)
    
    guess=getGuess(missedLetters+correctLetters)
    
    if guess in secretWord:
        correctLetters=correctLetters+guess
        
        foundAllLetters=True
        for i in range(len(secretWord)):
            if secretWord[i] not in correctLetters:
                foundAllLetters=False
                break
        if foundAllLetters:
            print("Yes! The secret worrd is '"+secretWord+"'! You have won!")
            gamesDone=True
    else:
        missedLetters=missedLetters+guess
        
        if len(missedLetters)==len(HANGMAN_PICS)-1:
            displayBoard(missedLetters,correctLetters,secretWord)
            print("You have run out of guesses!\nAfter "+str(len(missedLetters))+" missed guesses and "+str(len(correctLetters)+" correct guesses, the word was "+secretWord))
            gamesDone=True
            
    if gamesDone:
        if playAgain():
            missedLetters = ''
            correctLetters = ''
            gamesDone=False
            secretWord=getRandomWord(words)
        else:
            break