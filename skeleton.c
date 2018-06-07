#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/notifier.h>
#include <linux/kernel.h>

/*
   //add something like this in your board device tree
   skeleton@ff {
	compatible = "sd,skeleton";
	reg = <0xff 0x1000>;
   };
*/

static int skeleton_probe(struct platform_device *pdev){
    printk(KERN_ALERT "%s successful.\n",__func__);
    return 0;
}
static int skeleton_remove(struct platform_device *pdev){
    printk(KERN_ALERT "%s successful.\n",__func__);
    return 0;
}

static const struct of_device_id id_table[] = {
	{"sd,skeleton", 0},
	{}
};

MODULE_DEVICE_TABLE(of, id_table);

static struct platform_driver skeleton_driver = {
	.driver = {
		.name = "skeleton",
		.owner = THIS_MODULE,
	},
	.id_table = id_table,
	.probe = skeleton_probe,
	.remove = skeleton_remove,
};
module_platform_driver(skeleton_driver);
