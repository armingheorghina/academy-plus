echo "syntax on
set nu
set mouse=a
set shiftwidth=4
set tabstop=4
set hlsearch
highlight Normal ctermfg=grey ctermbg=black

if exists('+colorcolumn')
	  set colorcolumn=80
else
	  au BufWinEnter * let w:m2=matchadd('ErrorMsg', '\%>80v.\+', -1)
endif
" > ~/.vimrc
