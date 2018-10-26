                .data
pstring:        .asciiz "print \n"
                
                .text         

main:           
                li $v0,4
                la $a0,pstring
                syscall
