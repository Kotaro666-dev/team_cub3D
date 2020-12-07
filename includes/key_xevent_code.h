/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_xevent_code.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:37:01 by rnakai            #+#    #+#             */
/*   Updated: 2020/12/07 11:44:15 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_XEVENT_CODE_H
# define KEY_XEVENT_CODE_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_FOCUSIN		9
# define X_EVENT_KEY_EXIT		17

# define KEY_PRESS_MASK			1 << 0
# define KEY_RELEASE_MASK		1 << 1
# define STRUCTURE_NOTIFY_MASK	1 << 17
# define FOCUS_CHANGE_MASK		1 << 21

# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100
# define KEY_M					109
# define KEY_P					112
# define KEY_LEFT_ARROW			65361
# define KEY_RIGHT_ARROW		65363

#endif
