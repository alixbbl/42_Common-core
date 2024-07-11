/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:53:07 by alibourb          #+#    #+#             */
/*   Updated: 2023/11/05 12:19:00 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

/* LE BUT EST DE TRADUIRE CE CODE EN C++ :
int main(int ac, char **ag)
{
    int i = 1;
    int j = 0;
    if (ac == 1)
        printf("Blablabla");
    else
    {
        while (i < ac)
        {
            j = 0;
            while (ag[i][j])
            {
                ag[i][j] = toupper(ag[1][j]);
                write(1, &ag[1][j], 1);
                j++;
            }
            if (i < ac - 1)
                write(1, " ", 1);
            i++;
        }
    }
}
*/

int main(int ac, char **ag) {
    if (ac == 1)
        return ((std::cout << "* LOUD AND UNBEARABLE FEEDBACKNOISE *" << std::endl), 0);
    else {
        for (int i = 1; i < ac; i++) {
            for (int j = 0; ag[i][j] != '\0'; j++) {
                std::cout << (char)toupper((unsigned char)ag[i][j]); }
        }
    }
    std::cout << std::endl;
    return 0; }
