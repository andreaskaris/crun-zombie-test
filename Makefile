build:
	mkdir -p _output
	gcc zombies.c -o _output/zombies

clean:
	rm -f _output/*

build-container-image:
	podman build -t localhost/zombies:latest .

run-container-image-with-crun:
	podman --runtime /usr/bin/crun run -e CHILD_SLEEP_TIME=300 -e PARENT_SLEEP_TIME=5 --rm --memory 4M localhost/zombies:latest /usr/bin/zombies
