
include ./rules.mk

TARGET = main
LATEX  = pdflatex < /dev/null
BIBTEX = bibtex

PDF    = $(TARGET).pdf

SRCS = $(shell find . -name '*.tex' -type f -print)
FIGS = $(shell find */Figs/ -name '*.pdf' -type f -print)
OUTS = $(shell find */examples/ -name '*.out' -type f -print)
BIBS = pip.bib

all : clean examples Makefile
	rm -f $(PDF)
	make $(PDF)

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
	$(LATEX)  $(TARGET)
	$(BIBTEX) $(TARGET)
	rerun_count=5; rcount=0; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' $(TARGET).log; \
	    do \
	      if [ $${rcount} -ge $${rerun_count} ]; then \
		echo 'Something goes wrong'; exit 1; \
	      fi; \
	      echo "Rerunning latex .... ($${rerun_count})" ;\
	      rm -f $(TARGET).log; \
	      $(LATEX) $(TARGET); \
	      makeindex -l $(TARGET).idx; \
	      rcount=`expr $${rcount} + 1` ;\
	    done 
	grep    -e "LaTeX\ Warning" \
		-e "Package\ natbib\ Warning" \
		-e "undefined" \
		-e "multiply\ defined" \
		$(TARGET).log

clean-hook: 
	$(RM) *.lol *.lof *.lot *.toc *.bbl *.blg *.bbl
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

