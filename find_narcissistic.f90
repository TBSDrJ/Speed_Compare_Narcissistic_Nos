program find_narcissistic
    implicit none
    
    integer :: digits(9)
    integer :: i, j, n, num_digits, narcissism_sum
    ! integer :: fout
    ! real :: start, finish

    ! call cpu_time(start)
    ! open(newunit = fout, file="narcissistic_nos_fortran.txt", status="new", action="write")
    do n = 1, 10000000
        digits(:) = 0
        narcissism_sum = 0
        call get_digits(n, digits, num_digits)
        do i = 1, 9
            narcissism_sum = narcissism_sum + digits(i)**num_digits
        end do
        if (n == narcissism_sum) then
            print *, n
            ! write (fout, *) n
        end if

    end do
    ! call cpu_time(finish)
    ! print *, finish - start
    ! write (fout, *) "Time to complete: ", finish - start
    ! close(fout)


contains

    subroutine get_digits(n, digits, num_digits)
        integer, intent(in) :: n
        integer, intent(out) :: digits(:)
        integer, intent(out) :: num_digits
        integer :: i, modulus, n_truncated

        n_truncated = n
        i = 1
        do while(n_truncated > 0)
            modulus = mod(n_truncated, 10)
            digits(i) = modulus
            n_truncated = (n_truncated - modulus) / 10
            i = i + 1
        end do
        num_digits = i - 1
    end subroutine

end program find_narcissistic