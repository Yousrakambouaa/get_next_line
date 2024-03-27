/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykamboua <ykamboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:56:07 by ykamboua          #+#    #+#             */
/*   Updated: 2024/03/13 15:17:51 by ykamboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 
// C Program to illustrate the static variable lifetime
#include <stdio.h>
 
// function with static variable
int fun()
{
    static int count = 0;
    count++;
    return count;
}
 
int main()
{
    printf("%d ", fun());
    printf("%d ", fun());
    return 0;
}