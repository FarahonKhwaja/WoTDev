INSERT INTO rbac_permissions (id,name) VALUES (1000,"utility change race");
INSERT INTO rbac_permissions (id,name) VALUES (1001,"utility change faction");
INSERT INTO rbac_permissions (id,name) VALUES (1002,"utility maxskills");
INSERT INTO rbac_permissions (id,name) VALUES (1003,"utility customize");


INSERT INTO rbac_linked_permissions(id,linkedID) VALUES (199,1000);
INSERT INTO rbac_linked_permissions(id,linkedID) VALUES (199,1001);
INSERT INTO rbac_linked_permissions(id,linkedID) VALUES (199,1002);
INSERT INTO rbac_linked_permissions(id,linkedID) VALUES (199,1003);