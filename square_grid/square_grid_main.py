import os
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt


class ImageGrid:
    def __init__(self, images_path):
        self.images_path = images_path
        self.image_files = []
        self.images = []

    def load_images(self):
        self.image_files = [file for file in os.listdir(self.images_path) if file.endswith((".jpg", ".png"))]

        for file in self.image_files:
            file_path = os.path.join(self.images_path, file)
            image = Image.open(file_path)
            image_array = np.array(image)
            self.images.append(image_array)

    def create_image_grid(self):
        num_of_images = len(self.images)

        images_per_row = int(np.ceil(np.sqrt(num_of_images)))
        images_per_column = int(np.ceil(num_of_images / images_per_row))

        max_width = max(image.shape[1] for image in self.images)
        max_height = max(image.shape[0] for image in self.images)

        grid = np.empty((images_per_column, images_per_row), dtype=np.ndarray)

        for i, image in enumerate(self.images):
            row = i // images_per_row
            col = i % images_per_row

            height, width, _ = image.shape
            x_start = (max_width - width) // 2
            y_start = (max_height - height) // 2

            new_image = np.zeros((max_height, max_width, 3), dtype=np.uint8)
            new_image[y_start:y_start + height, x_start:x_start + width] = image

            grid[row, col] = new_image

        hori_concat = [np.hstack(grid[row, :]) for row in range(images_per_column)]
        image_grid = np.vstack(hori_concat)

        return image_grid

    def display_image_grid(self):
        image_grid = self.create_image_grid()

        plt.imshow(image_grid)
        plt.axis('off')
        plt.show()


image_directory = '/home/gpaudel/Documents/images/'

image_grid = ImageGrid(image_directory)
image_grid.load_images()
image_grid.display_image_grid()