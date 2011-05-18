all:
	g++ -c ip.c msg.c peer.c sockwrap.c node.c

testcli:
	gcc ip.c msg.c peer.c sockwrap.c node.c test/client.c -o client

testsrv:
	gcc ip.c msg.c peer.c sockwrap.c node.c test/server.c -o server

clean:
	rm *.o client server

#------------ git ops ------------#
commit:
	git commit -am 'no comments'
	git push origin master
