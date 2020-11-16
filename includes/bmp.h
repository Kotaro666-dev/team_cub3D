/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:52:41 by kkamashi          #+#    #+#             */
/*   Updated: 2020/11/15 19:21:49 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <unistd.h>
# include "libft.h"
# include "utilities.h"

/*
** REFERENCE: https://github.com/ohmae/image-io/blob/master/bmp_simple.c
** SITE: https://www.mm2d.net/main/prog/c/image_io-05.html
*/

# define FILE_TYPE 0x4D42    /**< "BM"をリトルエンディアンで解釈した値 */
# define FILE_HEADER_SIZE 14 /**< BMPファイルヘッダサイズ */
# define INFO_HEADER_SIZE 40 /**< Windowsヘッダサイズ */
# define DEFAULT_HEADER_SIZE (FILE_HEADER_SIZE + INFO_HEADER_SIZE)

/*
** @brief BMPファイルヘッダ
**
** メモリマップとして利用するには
** pragmaが必要
*/

# pragma pack(2)

typedef struct	s_bitmap_file_header
{
	uint16_t	bf_type;      /**< ファイルタイプ、必ず"BM" */
	uint32_t	bf_size;      /**< ファイルサイズ */
	uint16_t	bf_reserved1; /**< リザーブ */
	uint16_t	bf_reserved2; /**< リサーブ */
	uint32_t	bf_offbits;   /**< 先頭から画像情報までのオフセット、ヘッダ構造体＋パレットサイズ */
}				t_bitmap_file_header;

# pragma pack()

/*
** @brief 画像情報ヘッダ
*/

typedef struct	s_bitmap_info_header
{
	uint32_t	biSize;         /**< この構造体のサイズ */
	int32_t		biWidth;         /**< 画像の幅 */
	int32_t		biHeight;        /**< 画像の高さ */
	uint16_t	biPlanes;       /**< 画像の枚数、通常1 */
	uint16_t	biBitCount;     /**< 一色のビット数 */
	uint32_t	biCompression;  /**< 圧縮形式 */
	uint32_t	biSizeImage;    /**< 画像領域のサイズ */
	int32_t		biXPelsPerMeter; /**< 画像の横方向解像度情報 */
	int32_t		biYPelsPerMeter; /**< 画像の縦方向解像度情報*/
	uint32_t	biClrUsed;      /**< カラーパレットのうち実際に使っている色の個数 */
	uint32_t	biClrImportant; /**< カラーパレットのうち重要な色の数 */
}				t_bitmap_info_header;

#endif
