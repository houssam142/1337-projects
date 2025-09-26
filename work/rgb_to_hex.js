/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:07:47 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/21 22:30:36 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function isDigit(char)
{
    return (char >= '0' && char <= '9')
}

function rgbToHex(str)
{
	let num = 0
	let newstr = str.split("rgb(").join("");
	newstr = newstr.replace(", ", "");
    return newstr;
}

let rgb = "rgb(255, 255, 255)"

let res = rgbToHex(rgb)

console.log(res)