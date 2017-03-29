
# Check which TeX Live installation you have with the command pdflatex --version
TEXLIVE  = 2015
LATEX    = latex
PDFLATEX = pdflatex
BIBTEX   = bibtex
DVIPS    = dvips
DVIPDF   = dvipdf

#-------------------------------------------------------------------------------
# The main document filename
BASENAME = report
#-------------------------------------------------------------------------------
# Adjust this according to your top-level figures directory
# This directory tree is used by the "make cleanepstopdf" command
FIGSDIR  = figures
#-------------------------------------------------------------------------------

# EPSTOPDFFILES = `find . -name \*eps-converted-to.pdf`
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
EPSTOPDFFILES = $(call rwildcard, $(FIGSDIR), *eps-converted-to.pdf)

# Default target - make report.pdf with pdflatex
default: run_pdflatex

.PHONY: new newtexmf newbook newbooktexmf draftcover preprintcover auxmat \
	clean cleanpdf help

# Standard pdflatex target
run_pdflatex: $(BASENAME).pdf
	@echo "Made $<"

#-------------------------------------------------------------------------------
# Specify the tex and bib file dependencies for running pdflatex
# If your bib files are not in the main directory adjust this target accordingly
#%.pdf:	%.tex *.tex bibtex/bib/*.bib
%.pdf:	%.tex *.tex *.bib
	$(PDFLATEX) $<
	-$(BIBTEX)  $(basename $<)
	$(PDFLATEX) $<
	$(PDFLATEX) $<
#-------------------------------------------------------------------------------

new:
	if [ $(TEXLIVE) -ge 2007 -a $(TEXLIVE) -lt 2100 ]; then \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-document.tex | \
	    sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' >$(BASENAME).tex; \
	else \
	  echo "Invalid value for TEXLIVE: $(TEXLIVE)"; \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-document.tex >$(BASENAME).tex; \
	fi
	cp template/atlas-document-metadata.tex $(BASENAME)-metadata.tex
	touch $(BASENAME).bib
	touch $(BASENAME)-defs.sty

newtexmf:
	if [ $(TEXLIVE) -ge 2007 -a $(TEXLIVE) -lt 2100 ]; then \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-document-texmf.tex | \
	    sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' >$(BASENAME).tex; \
	else \
	  echo "Invalid value for TEXLIVE: $(TEXLIVE)"; \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-document-texmf.tex >$(BASENAME).tex; \
	fi
	cp template/atlas-document-metadata.tex $(BASENAME)-metadata.tex
	touch $(BASENAME).bib
	touch $(BASENAME)-defs.sty

newbook:
	if [ $(TEXLIVE) -ge 2007 -a $(TEXLIVE) -lt 2100 ]; then \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-book.tex | \
	    sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' >$(BASENAME).tex; \
	else \
	  echo "Invalid value for TEXLIVE: $(TEXLIVE)"; \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-book.tex >$(BASENAME).tex; \
	fi
	cp template/atlas-document-metadata.tex $(BASENAME)-metadata.tex
	touch $(BASENAME).bib
	touch $(BASENAME)-defs.sty

newbooktexmf:
	if [ $(TEXLIVE) -ge 2007 -a $(TEXLIVE) -lt 2100 ]; then \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-book-texmf.tex | \
	    sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' >$(BASENAME).tex; \
	else \
	  echo "Invalid value for TEXLIVE: $(TEXLIVE)"; \
	  sed s/atlas-document/$(BASENAME)/ template/atlas-book-texmf.tex >$(BASENAME).tex; \
	fi
	cp template/atlas-document-metadata.tex $(BASENAME)-metadata.tex
	touch $(BASENAME).bib
	touch $(BASENAME)-defs.sty

draftcover:
	if [ $(TEXLIVE) -ge 2007 -a $(TEXLIVE) -lt 2100 ]; then \
	  sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' template/atlas-draft-cover.tex \
	    >$(BASENAME)-draft-cover.tex; \
	else \
	  echo "Invalid value for TEXLIVE: $(TEXLIVE)"; \
	  cp  template/$(BASENAME)-draft-cover.tex $(BASENAME)-draft-cover.tex; \
	fi

preprintcover:
	sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' template/atlas-preprint-cover.tex >$(BASENAME)-preprint-cover.tex
	#cp template/atlas-preprint-cover.tex $(BASENAME)-preprint-cover.tex

auxmat:
	sed s/atlas-document/$(BASENAME)/ template/atlas-auxmat.tex | \
	sed 's/texlive=20[0-9][0-9]/texlive=$(TEXLIVE)/' >$(BASENAME)-auxmat.tex

run_latex: dvipdf

# Targets if you run latex instead of pdflatex
dvipdf:	$(BASENAME).dvi
	$(DVIPDF) -sPAPERSIZE=a4 -dPDFSETTINGS=/prepress $<
	@echo "Made $(basename $<).pdf"

dvips:	$(BASENAME).dvi
	$(DVIPS) $<
	@echo "Made $(basename $<).ps"

# Specify dependencies for running latex
#%.dvi:	%.tex tex/*.tex bibtex/bib/*.bib
%.dvi:	%.tex *.tex *.bib
	$(LATEX)    $<
	-$(BIBTEX)  $(basename $<)
	$(LATEX)    $<
	$(LATEX)    $<

%.bbl:	%.tex *.bib
	$(LATEX) $<
	$(BIBTEX) $<



clean:
	-rm *.dvi *.toc *.aux *.log *.out \
		*.bbl *.blg *.brf *.bcf *-blx.bib *.run.xml \
		*.cb *.ind *.idx *.ilg *.inx \
		*.synctex.gz *~ ~* spellTmp 


