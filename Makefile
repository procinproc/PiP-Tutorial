
include ./rules.mk

TARGET = main
LATEX  = pdflatex < /dev/null

PDF    = $(TARGET).pdf

SRCS = $(shell find . -name '*.tex' -type f -print)
FIGS = $(shell find */Figs/ -name '*.pdf' -type f -print)
OUTS = $(shell find */examples/ -name '*.out' -type f -print)
BIBS = pip.bib

all : clean examples $(PDF) Makefile

pipkw.sh: pip-keywords.sh
	./pip-keywords.sh

examples: pipkw.sh
	find . -name examples -print | \
		while read ex; do \
			echo $$ex; \
			make -C $$ex; \
		done
.PHONY: examples

$(PDF): $(SRCS) $(FIGS) $(OUTS) $(BIBS)
	$(RM) $(TARGET).idx
	$(LATEX) $(TARGET)
	rerun_count=5; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' $(TARGET).log; \
	    do \
	      if [ $${rerun_count} -eq 0 ]; then \
		echo 'Something goes wrong'; exit 1; \
	      fi; \
	      echo "Rerunning latex .... ($${rerun_count})" ;\
	      rm -f $(TARGET).log; \
	      $(LATEX) $(TARGET); \
	      makeindex -l $(TARGET).idx; \
	      rerun_count=`expr $${rerun_count} - 1` ;\
	    done 
	grep    -e "LaTeX\ Warning" \
		-e "Package\ natbib\ Warning" \
		-e "undefined" \
		-e "multiply\ defined" \
		$(TARGET).log

clean-hook: 
	$(RM) *.lol *.lof *.lot *.toc *.bbl *.blg 
	$(RM) *.idx *.ilg *.ind *.out *.aux *.log
	find ./*/ -name Makefile -print | \
		while read ex; do \
			dir=$$(dirname $$ex); \
			make -C $$dir clean; \
		done

veryclean-hook: clean 
	$(RM) $(PDF) pipkw.sh 
	find ./*/ -name Makefile -print | \
		while read ex; do \
			dir=$$(dirname $$ex); \
			make -C $$dir veryclean; \
		done

