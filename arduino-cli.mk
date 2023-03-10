arduino-cli=/opt/arduino/arduino-cli
libraries=${HOME}/.arduino15/libraries/
build-path=build-${board}

ifndef board
$(error board is undefined)
endif

compile:
	rm -fr ${build-path}
	${arduino-cli} compile --libraries=${libraries} -b ${board} --build-path=${build-path}

upload: compile
	${arduino-cli} upload -b ${board} --input-dir=${build-path} --port /dev/ttyUSB0
