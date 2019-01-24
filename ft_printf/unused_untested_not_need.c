void    spec_string_l(t_printf *prtf, va_list args,)
{
    wchar_t *wtmp;
    int     dif;

    wtmp = va_arg(args, wchar_t*);
    if (ft_wcharlen(wtmp) > prtf->args.pre && prtf->args.pre != 0)
        wtmp = ft_strsub(wtmp, 0, prtf->args.pre);
    if ((dif = ft_cont_less_width(ft_wcharlen(wtmp), prtf->args.width)) > 0)
    {
        if (NOT1(prtf->args.flags.left_just))
        {
            ft_lstadd(&(prtf->output), ft_lstnew(wtmp, ft_wcharlen(wtmp)));
            create_width(&(prtf->output), dif, 7);
        }
        else
        {
            create_width(&(prtf->output), dif, 0);
            ft_lstadd(&(prtf->output), ft_lstnew(wtmp, ft_wcharlen(wtmp)));
        }
    }
    else
        ft_lstadd(&(prtf->output), ft_lstnew(wtmp, ft_wcharlen(wtmp)));
}

void    spec_char_l(t_printf *prtf, va_list args, int dif)
{
    wchar_t     tmp[2];

    tmp[0] = (wchar_t)va_arg(args, unsigned int);
    tmp[1] = '\0';
    if (dif > 0)
    {
        if (NOT1(prtf->args.flags.left_just))
        {
            ft_lstadd(&(prtf->output), ft_lstnew(tmp, 1));
            create_width(&(prtf->output), dif, 7);
        }
        else 
        {
            create_width(&(prtf->output), dif, 7);
            ft_lstadd(&(prtf->output), ft_lstnew(tmp, 1));
        }
    }
    else
        ft_lstadd(prtf->output, ft_lstnew(tmp, 1));
}

size_t  ft_wcharlen(wchar_t *data)
{
    size_t len;

    len = 0;
    while (data++ != 0)
    {
        len++;
    }
    return (len);
}

