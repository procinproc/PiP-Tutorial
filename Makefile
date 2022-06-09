TARGET = main
BIBS   = pip.bib
LATEX  = pdflatex

PDF    = $(TARGET).pdf

SRCS = $(shell find .    -name '*.tex' -print)
FIGS = $(shell find figs -name '*.pdf' -print)
PRGS = $(shell find prgs -name '*.c'   -print)

all : $(PDF)

pipkw.sh: pip-keywords.sh
	./pip-keywords.sh

examples: pipkw.sh
	find . -name examples -print | \
		while read ex; do \
			echo $$ex; \
			make -C $$ex; \
		done

$(PDF): examples $(SRCS) $(FIGS) $(PRGS) $(BIBS) Makefile
	pdflatex $(TARGET)
	rerun_count=5 ; \
	while egrep -s 'Rerun (LaTeX|to get cross-references right)' $(TARGET).log; \
	    do \
	      if [ $${rerun_count} -eq 0 ]; then \
		echo 'Something goes wrong'; exit 1; \
	      fi; \
	      echo "Rerunning latex .... ($${rerun_count})" ;\
	      rm -f $(TARGET).log; \
	      pdflatex $(TARGET); \
	      makeindex -l $(TARGET).idx; \
	      rerun_count=`expr $${rerun_count} - 1` ;\
	    done 
	grep \
	-e "LaTeX\ Warning" \
	-e "Package\ natbib\ Warning" \
	-e "undefined" \
	-e "multiply\ defined" \
	$(TARGET).log; \

clean: 
	rm -f $(PDF) *.lol *.lof *.lot *.toc *.bbl *.blg *.out *.aux *.log \
	*.idx *.ilg *.ind *~ *.dvi
	find ./*/ -name Makefile -print | \
		while read ex; do \
			dir=$$(dirname $$ex); \
			make -C $$dir clean; \
		done

veryclean: clean 
	rm -f $(PDF) pipkw.sh 
	find ./*/ -name Makefile -print | \
		while read ex; do \
			dir=$$(dirname $$ex); \
			make -C $$dir veryclean; \
		done

distclean: veryclean

