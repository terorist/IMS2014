PROJECT=xjaluv02
INCLUDES := $(wildcard *.tex)
#PDFLATEX_OPTS=-aux-directory=tmp
#BIBTEX_OPTS=-include-directory=tmp

all: $(PROJECT).pdf

$(PROJECT).pdf: $(INCLUDES)
	pdflatex -draftmode $(PDFLATEX_OPTS) $(PROJECT) --max-print-line=1000
	bibtex $(PDFLATEX_OPTS) $(PROJECT)
	pdflatex -draftmode $(PDFLATEX_OPTS) $(PROJECT) --max-print-line=1000 -quiet
	pdflatex $(PDFLATEX_OPTS) $(PROJECT) --max-print-line=1000

clean:
	rm -f $(PROJECT).{pdf,blg,bbl,aux,out,synctex.gz,ilg,lot,txt,lof,toc}