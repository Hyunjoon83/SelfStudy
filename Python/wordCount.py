sentence=input()
wordList=sentence.split()

word_cnt_dict={}
for word in wordList:
    if word in word_cnt_dict.keys():
        word_cnt_dict[word]+=1
    else:
        word_cnt_dict[word]=1;
        
for word in word_cnt_dict.keys():
    print(word+": ",word_cnt_dict[word])