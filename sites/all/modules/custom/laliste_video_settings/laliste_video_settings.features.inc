<?php
/**
 * @file
 * laliste_video_settings.features.inc
 */

/**
 * Implements hook_video_default_presets().
 */
function laliste_video_settings_video_default_presets() {
  $items = array(
    'laliste_video_preset' => array(
      'name' => 'laliste_video_preset',
      'description' => 'Provides default laliste video preset',
      'settings' => array(
        'video_extension' => 'mp4',
        'video_codec' => 'h264',
        'video_preset' => '',
        'video_quality' => 5,
        'video_speed' => 1,
        'wxh' => '640x360',
        'video_aspectmode' => 'preserve',
        'video_upscale' => 0,
        'audio_codec' => 'aac',
        'audio_quality' => 5,
        'deinterlace' => 'detect',
        'max_frame_rate' => '',
        'frame_rate' => '',
        'keyframe_interval' => '',
        'video_bitrate' => '',
        'bitrate_cap' => '',
        'buffer_size' => '',
        'one_pass' => 0,
        'skip_video' => 0,
        'h264_profile' => '',
        'audio_bitrate' => '',
        'audio_channels' => 2,
        'audio_sample_rate' => '',
        'skip_audio' => 0,
        'video_watermark_enabled' => 0,
        'video_watermark_fid' => 0,
        'video_watermark_x' => 5,
        'video_watermark_y' => 5,
        'video_watermark_width' => '',
        'video_watermark_height' => '',
        'video_watermark_origin' => 'content',
        'autolevels' => 0,
        'deblock' => 0,
        'denoise' => '',
        'clip_start' => '',
        'clip_length' => '',
      ),
    ),
  );
  return $items;
}
