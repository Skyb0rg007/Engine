function! AddToInclude(dir)
    let g:ale_c_gcc_options .= ' -I' . a:dir
    let &path .= ',' . a:dir
endfunction

let ale_c_gcc_options='-Wall -std=c11 -pedantic -Wvla -Winline -D_REENTRANT -DRESOURCE_DIR=""'
call AddToInclude("/usr/include/SDL2")
call AddToInclude("Engine/include")
call AddToInclude("Engine/include/public")
call AddToInclude("Runner/include")
call AddToInclude("Runner/include/public")

call AddToInclude("libs/cglm/include")
call AddToInclude("libs/klib/include")

command! -nargs=0 Cmake !cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug
command! -nargs=0 CmakeFinal !cmake -H. -Bfinal-build -DCMAKE_BUILD_TYPE=Release
set makeprg=cmake\ --build\ build\ --parallel\ 4\ --
nnoremap <F5> :make!<CR>

let g:doxygen_javadoc_autobrief = 0

augroup project
    autocmd!
    autocmd BufRead,BufNewFile *.h set filetype=c.doxygen
    autocmd BufRead,BufNewFile *.c set filetype=c.doxygen

    autocmd BufRead,BufNewFile *.h.in ALEDisableBuffer
    autocmd BufRead,BufNewFile *.h.in set filetype=c.doxygen
augroup END

