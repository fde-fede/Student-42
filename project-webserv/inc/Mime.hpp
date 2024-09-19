/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mime.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:32:10 by fde-fede          #+#    #+#             */
/*   Updated: 2024/05/31 18:32:11 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIME_HPP
#define MIME_HPP

#include "Webserv.hpp"

class Mime
{
    public:
        Mime();
        std::string getMimeType(std::string extension);
    private:
        std::map<std::string, std::string> _mime_types;
        
};




#endif// MIME_HPP