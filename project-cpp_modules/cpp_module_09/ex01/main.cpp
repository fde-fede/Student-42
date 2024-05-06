/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:11:40 by fde-fede          #+#    #+#             */
/*   Updated: 2024/05/06 09:25:11 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return EXIT_FAILURE;
    }

    RPN rpn;
    rpn.run(av[1]);

    return EXIT_SUCCESS;
}