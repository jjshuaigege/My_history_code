import re
words="我警告你！我很生气！！后果自负"
w_l=words.split("！")
for i in range(len(w_l)):
    print(w_l[i])

#多个分隔串,需要用到re库
text="""The Tragedy of Hamlet, Prince of Denmark
Shakespeare homepage | Hamlet | Entire play
ACT I

SCENE I. Elsinore. A platform before the castle.

FRANCISCO at his post. Enter to him BERNARDO
BERNARDO
Who's there?
FRANCISCO
Nay, answer me: stand, and unfold yourself.
BERNARDO
Long live the king!
FRANCISCO
Bernardo?
BERNARDO
He."""
o_c=re.split(",| |:|\n|'|!|\.|\?",text)  #分隔串用|隔开
for i in o_c:
    print(i,end=" ")
