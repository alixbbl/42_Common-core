/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:01:32 by alibourb          #+#    #+#             */
/*   Updated: 2024/01/22 11:00:45 by alibourb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
    /* TYPE : INT */
    int a = 6;
    int b = 9;
    std::cout << "Max is : "<< ::max<int>(a, b) << std::endl;
    std::cout << "Min is : " << ::min<int>(a, b) << std::endl;
    std::cout << "Before swap - a: " << a << ", b: " << b << std::endl;
    swap(a, b);
    std::cout << "After swap - a: " << a << ", b: " << b << std::endl;

    /* TYPE : FLOAT */
    std::cout << std::endl;
    float af = 6.86f;
    float bf = -899.567f;
    std::cout << "Max is : "<< ::max<float>(af, bf) << std::endl;
    std::cout << "Min is : " << ::min<float>(af, bf) << std::endl;
    std::cout << "Before swap - af: " << af << ", bf: " << bf << std::endl;
    swap(af, bf);
    std::cout << "After swap - af: " << af << ", bf: " << bf << std::endl;

    /* TYPE : STRING */
    std::cout << std::endl;
    std::string str1 = "ahouaisok";
    std::string str2 = "cestquoicetexempledemerde";
    std::cout << "Max is : "<< ::max<std::string>(str1, str2) << std::endl;
    std::cout << "Min is : " << ::min<std::string>(str1, str2) << std::endl;
    std::cout << "Before swap - str1: " << str1 << ", str2: " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap - str1: " << str1 << ", str2: " << str2 << std::endl;
    return 0;
}

// int main( void ) {
//  int a = 2;
//  int b = 3;
//  ::swap( a, b );
//  std::cout << "a = " << a << ", b = " << b << std::endl;
//  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//  std::string c = "chaine1";
//  std::string d = "chaine2";
//  ::swap(c, d);
//  std::cout << "c = " << c << ", d = " << d << std::endl;
//  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//  return 0;
// }

// int main() {
//     Awesome a(2), b(4);
//     swap(a, b);
//     std::cout << a << " " << b << std::endl;
//     std::cout << max(a, b) << std::endl;
//     std::cout << min(a, b) << std::endl;
// }
