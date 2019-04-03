help:
	@echo "usage: make target.pdf will compile target.tex to target.pdf "

.PHONY:clean

%.pdf:%.tex
	@pdflatex -shell-escape $<

clean:
	@rm -f *.aux *.log *.idx *.ind *.ilg *.toc *.los *.lot *.lof *.snm *.nav *.out *.blg *.bak
