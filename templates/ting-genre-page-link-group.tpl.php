<?php

/**
 * Default HTML for displaying a link group.
 *
 * Available variables:
 *  - $link_items
 *    The raw array of link items for this link group.
 *  - $rows
 *    An array of link item rows for this link group.
 */

?>

<?php if ($rows): ?>
	<div id="ting-genre-page-link-group" class="group-blocks--wrapper <?php print $classes ?>" <?php print $attributes ?>>
		<?php foreach ($rows as $row): ?>
			<div class="<?php print $row['class']; ?> group-blocks--inner">
				<?php foreach($row['columns'] as $column_class => $column): ?>
					<div class="<?php print $column_class; ?>">
						<a href="<?php print $column['url']; ?>">
							<?php print render($column['image']); ?>
							<h2><?php print render($column['title']); ?></h2>
						</a>
					</div>
				<?php endforeach; ?>
			</div>
		<?php endforeach; ?>
	</div>
<?php endif; ?>