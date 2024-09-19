/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:31:10 by fde-fede          #+#    #+#             */
/*   Updated: 2024/09/19 19:01:42 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Webserv.hpp"
#include "../inc/ServerManager.hpp"

void sigpipeHandle(int sig) { if(sig) {}}

int main(int argc, char **argv) 
{
	// Logger::setState(OFF);
	if (argc == 1 || argc == 2) {
		try 
		{
			std::string		config;
			ConfigParser	cluster;
        	ServerManager 	master;
			signal(SIGPIPE, sigpipeHandle);
			/* configuration file as argument or default path */
			config = (argc == 1 ? "configs/default.conf" : argv[1]);
			cluster.createCluster(config);
			// cluster.print(); // for checking
			master.setupServers(cluster.getServers());
			master.runServers();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (1);
		}
    }
    else 
	{
		Logger::logMsg(RED, CONSOLE_OUTPUT, "Error: wrong arguments");
		return (1);
	}
    return (0);
}

