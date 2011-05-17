all:
	g++ -c ip.c msg.c peer.c sockwrap.c node.c

clean:
	rm *.o


testsrv:
	gcc ip.c msg.c peer.c sockwrap.c node.c test/server.c -o server

testsrv:
	gcc ip.c msg.c peer.c sockwrap.c node.c test/client.c -o client

#------------ git ops ------------#
commit:
	git commit -am 'no comments'
	git push origin master
