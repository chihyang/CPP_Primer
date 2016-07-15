# Clean or make all of the chapters.

chapters = $(wildcard chap*)
cleanchap = $(chapters)

.PHONY: all $(chapters) clean $(cleanchap)

all: $(chapters)

$(chapters):
	$(MAKE) -C $@

clean: $(cleanchap)

$(cleanchap):
	$(MAKE) -C $@ clean
