all:
	g++ -c ip.c msg.c peer.c sockwrap.c node.c

clean:
	rm *.o

#------------ git ops ------------#
commit:
	git commit -am 'no comments'
	git push origin master
