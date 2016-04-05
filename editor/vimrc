"Set terminal color mode to 256
set t_Co=256

"Move cursor to search result as you type
set incsearch

"Allow wildmenu, give a list of candidate command
set wildmenu

"Turn on invisible characters
"set list

"Turn on autoindent
set autoindent

" set backspace to resolve 'cannot use delete' problem
set backspace=indent,eol,start

"Turn on tab size, used to indent 8 
set ts=4

"Ignore case when seaching
"set ignorecase

"Close compatible mode
"set nocompatiple

"Show filename in title barr
set title

"Do not wrap lines
"set nowrap

"Set scroll off line number
set scrolloff=5

"Map function buttons to commands
map <F2> :tabnew<CR>
map <F3> gt		"go to the other tab
map <F5> :PREVCOLOR<CR>
map <F6> :NEXTCOLOR<CR>

"Better pasting with paste mode
"set paste

set wildmode=list:longest,full
set tabstop=4	
set smartindent "smart indent
set shiftwidth=4

" Mar 29, 2015,
"Set <Leader> key
let mapleader=":"
"Open file type detection
filetype on
filetype plugin on

"shortcuts for navigating windows
nnoremap <Leader>wl <C-W>l
nnoremap <Leader>wh <C-W>h
nnoremap <Leader>wj <C-W>j
nnoremap <Leader>wk <C-W>k

"Set shortcuts
"Copy system clipboard to vim
vnoremap <Leader>p "+p

"Settings of pathogen
runtime bundle/pathogen/autoload/pathogen.vim
"Run pathogen
execute pathogen#infect()

"State bar
set laststatus=2
"Cursor current position
set ruler
"Turn on line number
set number
"Highlight current cursor line
set cursorline
"Highlight search result
set hlsearch
"nowarp
set nowrap
"Turn on sytax highlight on
syntax enable
syntax on

"Choose your color scheme
set background=dark
"colorscheme mustang
colorscheme molokai

"set indentation
filetype indent on
"transform tab into #tabstop or #shiftwidth spaces
set expandtab
set tabstop=4
set shiftwidth=4
set softtabstop=4

"code folding 
"set foldmethod=indent
set foldmethod=syntax
"no folding when open vim
set nofoldenable

"ctags settings
nmap <Leader>tn :tnext<CR>
nmap <Leader>tp :tprevious<CR>
"set indexer parameters for ctags
let g:indexer_ctagsCommandLineOptions="--c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"

"YCM settings
nnoremap <leader>jd :YcmCompleter GoToDeclaration<CR>
"Only #include or opened files
nnoremap <leader>je :YcmCompleter GoToDefinition<CR>

"tagbar settings
" set tagbar sub-window to appear in the left 
let tagbar_left=1 
" set show/hide tag list shortcut：tag list 
nnoremap <Leader>tl :TagbarToggle<CR> 
" set tagbar width 
let tagbar_width=32 
" tagbar don't show much unnecessary information
let g:tagbar_compact=1
" In default ctags doesn't process local variables, function declaration and such,
" set tagbar_type_cpp to change this default settting.
let g:tagbar_type_cpp = {
    \ 'kinds' : [
        \ 'd:macros:1',
        \ 'g:enums',
        \ 't:typedefs:0:0',
        \ 'e:enumerators:0:0',
        \ 'n:namespaces',
        \ 'c:classes',
        \ 's:structs',
        \ 'u:unions',
        \ 'f:functions',
        \ 'm:members:0:0',
        \ 'v:global:0:0',
        \ 'x:external:0:0',
        \ 'l:local:0:0'
     \ ],
     \ 'sro'        : '::',
     \ 'kind2scope' : {
         \ 'g' : 'enum',
         \ 'n' : 'namespace',
         \ 'c' : 'class',
         \ 's' : 'struct',
         \ 'u' : 'union'
     \ },
     \ 'scope2kind' : {
         \ 'enum'      : 'g',
         \ 'namespace' : 'n',
         \ 'class'     : 'c',
         \ 'struct'    : 's',
         \ 'union'     : 'u'
     \ }
\ }

" global search plugin vim.CtrlSF, this needs ack and ag
" search in project
nnoremap <Leader>sp :CtrlSF<CR>

" replace function
" confirm: whether to confirm before replace
" wholeword：the word need to be replace
" replace: the replace string
function! Replace(confirm, wholeword, replace)
    wa
    let flag = ''
    if a:confirm
        let flag .= 'gec'
    else
        let flag .= 'ge'
    endif
    let search = ''
    if a:wholeword
        let search .= '\<' . escape(expand('<cword>'), '/\.*$^~[') . '\>'
    else
        let search .= expand('<cword>')
    endif
    let replace = escape(a:replace, '/\&~')
    execute 'argdo %s/' . search . '/' . replace . '/' . flag . '| update'
endfunction
" replace word with confirmation 
nnoremap <Leader>rw :call Replace(1, 1, input('Replace '.expand('<cword>').' with: '))<CR>

"OmniCppComplete
let OmniCpp_DefaultNamespaces = ["_GLIBCXX_STD"]
set tags+=/usr/include/c++/4.8/stdcpp.tags

"NerdTree
nmap <leader>nt :NERDTree<CR>
let NERDTreeHighlightCursorline=1
let NERDTreeIgnore=[ '\.pyc$', '\.pyo$', '\.obj$', '\.o$', '\.so$', '\.egg$', '^\.git$', '^\.svn$', '^\.hg$' ]
let g:netrw_home='~/bak'
"close vim if the only window left open is a NERDTree
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endnmap <leader>nt :NERDTree<CR>
let NERDTreeHighlightCursorline=1
let NERDTreeIgnore=[ '\.pyc$', '\.pyo$', '\.obj$', '\.o$', '\.so$', '\.egg$', '^\.git$', '^\.svn$', '^\.hg$' ]
let g:netrw_home='~/bak'
"close vim if the only window left open is a NERDTree
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | end
