
RM = rm -f

all:

clean: clean-hook
	$(RM) *.exout *~ '#'* '.#'* .DS_STORE

veryclean: clean veryclean-hook
	$(RM) *.out

distclean: veryclean

clean-hook:
veryclean-hook:

.PHONY: clean veryclean distclean clean-hook veryclean-hook
